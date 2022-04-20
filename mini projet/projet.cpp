#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct voiture
		{int idVoiture;
		char marque[15];
		char nomVoiture[15];
		char couleur[7];
		int nbplaces;
		int prixJour;
		char EnLocation[4];
		}voiture;
		
typedef struct 
		{
			int jour;
			int mois;
			int annee;
		}date;

typedef struct 
		{
			float numContrat;
			int idVoiture;
			int idClient;
			date debut;
			date fin;
			int cout;
		}contrat;
		
typedef struct
		{
			int idClient;	
			char nom[20];
			char prenom[20];
			int cin;
			char adresse[15];
			int telephone;
		}client;
		
void MenuPrincipal(char*,char*,char*);
void MenuLocation(char*,char*,char*);
void MenuGestionVoitures(char*,char*,char*);
void MenuGestionClients(char*,char*,char*);
void ListeVoiture(char*);
void AjouterVoiture(char*);
void ModifierVoiture(char*);
void SupprimerVoiture(char*);
void VisualiserContrat(char*);
void LouerVoiture(char*,char*,char*);
void RetournerVoiture(char*,char*); 
void ModifierContrat(char*,char*);
void SupprimerContrat(char*,char*);
void ListeClients(char*);
void AjouterClient(char*);
void ModifierClient(char*);
void SupprimerClient(char*);


int main()
{char*voit=(char*)malloc(10*sizeof(char));
char*cli=(char*)malloc(10*sizeof(char));
char*cont=(char*)malloc(10*sizeof(char));
if(voit && cli &&cont){
	printf("le nom du fichier des voitures:");
	scanf("%s",voit);
	printf("le nom du fichier des clients:");
	scanf("%s",cli);
	printf("le nom du fichier des contrats:");
	scanf("%s",cont);}
else{printf("erreur d'allocation'");
exit(-1);
}
MenuPrincipal(voit,cli,cont);
free(voit);
free(cli);
free(cont);
}

void MenuPrincipal(char*fichv,char*fichc,char*fichct)
{int choix;
	do{
	printf("\n********MENU PRINCIPAL***********\n");
	printf(" _________________________________\n");
	printf("|Location........................1|\n");
	printf("|Gestion Voitures................2|\n");
	printf("|Gestion clients.................3|\n");
	printf("|Quitter.........................4|\n");
	printf("|_________________________________|\n");
	printf("           votre choix:             ");
	scanf("%d",&choix);
switch(choix)
	{
	case 1:MenuLocation(fichv,fichc,fichct);break;
	case 2:MenuGestionVoitures(fichv,fichc,fichct);break;
	case 3:MenuGestionClients(fichv,fichc,fichct);break;
	case 4:printf("vous avez choisi de quitter le programme");exit(-1);break;
	}}while(choix!=4);
		  
}
void MenuGestionVoitures(char*fichv,char*fichc,char*fichct)
{int choix;
do{
	printf("\n*******Gestion des Voitures*******\n");
	printf(" _________________________________\n");
	printf("|Liste des voitures..............1|\n");
	printf("|Ajouter voiture.................2|\n");
	printf("|Modifier voiture................3|\n");
	printf("|Supprimer voiture...............4|\n"); 
	printf("|Retour..........................5|\n");
	printf("|_________________________________|\n");	
	printf("          votre choix :");
	scanf("%d",&choix);
switch(choix)
	{case 1:ListeVoiture(fichv);break;
	case 2:AjouterVoiture(fichv);break;
	case 3:ModifierVoiture(fichv);break;
	case 4:SupprimerVoiture(fichv);break;
	case 5:MenuPrincipal(fichv,fichc,fichct);break;
	}
}while(choix!=5);
}
void MenuLocation(char*fichv,char*fichc,char*fichct)
{int choix;
do{
		printf("\n******Location d'une voiture********\n");
		printf(" ___________________________________\n");
		printf("|Visualiser contrat................1|\n");
		printf("|Louer voiture.....................2|\n");
		printf("|Retourner voiture.................3|\n");
		printf("|Modifier contrat..................4|\n");
		printf("|Supprimer contrat.................5|\n");
		printf("|Retour............................6|\n");
		printf("|___________________________________|\n");
		printf("       votre choix :");
	scanf("%d",&choix);
switch(choix)
	{case 1:VisualiserContrat(fichct);break;
	case 2:LouerVoiture(fichv,fichc,fichct);break;
	case 3:RetournerVoiture(fichv,fichct);break;
	case 4:ModifierContrat(fichv,fichct);break;
	case 5:SupprimerContrat(fichv,fichct);break;
	case 6:MenuPrincipal(fichv,fichc,fichct);break;
	}
 }while(choix!=6);
 }
void MenuGestionClients(char*fichv,char*fichc,char*fichct)
{int choix;
do{
		printf("\n*******Gestion des client********\n");
		printf(" ________________________________\n");
		printf("|Liste des clients..............1|\n");
		printf("|Ajouter client.................2|\n");
		printf("|Modifier client................3|\n");
		printf("|Supprimer client...............4|\n");
		printf("|Retour.........................5|\n");
		printf("|________________________________|\n");	
		printf("	   votre choix :");
	scanf("%d",&choix);
switch(choix)
	{case 1:ListeClients(fichc);break;
	case 2:AjouterClient(fichc);break;
	case 3:ModifierClient(fichc);break;
	case 4:SupprimerClient(fichc);break;
	case 5:MenuPrincipal(fichv,fichc,fichct);break;
	}	
 }while(choix!=5); 
}
void ListeVoiture(char*fichv)
{voiture voit;
int i=1;
FILE*v;
v=fopen(fichv,"rb");
if(!v) {printf("erreur d'ouverture du fichier %s",fichv);
 		exit(-1);}
else
	{fseek(v,0,SEEK_SET);
while(fread(&voit,sizeof(voiture),1,v))
	{printf(" voiture num :%d\n",i);
	printf("id :%d\n",voit.idVoiture);
	printf("marque:%s\n",voit.marque);
	printf("nom:%s\n",voit.nomVoiture);
	printf("couleur:%s\n",voit.couleur);
	printf("nombre de places:%d\n",voit.nbplaces);
	printf("prix/j:%d\n",voit.prixJour);
	printf("en location:%s\n",voit.EnLocation);
 	i++;
 }}
 fclose(v);
}
void AjouterVoiture(char*fichv)
 {voiture voit;
 FILE*v=fopen(fichv,"ab+");
 if(!v) {printf("erreur d'ouverture du fichier %s",fichv);
 		exit(-1);}
 else{
 	printf("l'id de la voiture:");
 	scanf("%d",&voit.idVoiture);
 	printf("la marque de la voiture:");
 	scanf("%s",voit.marque);
 	printf("le nom de la voiture:");
 	scanf("%s",voit.nomVoiture);
 	printf("la couleur:");
 	scanf("%s",voit.couleur);
 	printf("le nombre de place:");
 	scanf("%d",&voit.nbplaces);
 	printf("prix du jour:");
 	scanf("%d",&voit.prixJour);
 	printf("en location(oui/non):");
 	scanf("%s",voit.EnLocation);
fwrite(&voit,sizeof(voiture),1,v);
}
fclose(v);
}
void ModifierVoiture(char*fichv)
{voiture voit;
int id,trouve=0,taille=0,i=0;
FILE*v;
char choix;
v=fopen(fichv,"rb");
voiture *tv=(voiture*)malloc(100*sizeof(voiture));
if(!v)
{printf("erreur d'ouverture du fichier %s",fichv);
exit(-1);
}
if(!tv)
{printf("erreur d'allocation");
exit(-1);
}
if(v!=NULL && tv!=NULL)
{printf("l'id de la voiture a modifier:");
scanf("%d",&id);
while(fread(&voit,sizeof(voiture),1,v))
	{taille++;
	if(voit.idVoiture!=id)
		{tv[i]=voit;
		i++;}
	else{
		printf("voulez vous modifier l'id ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
		printf("le nouveau id de la voiture:");
		fflush(stdin);
 		scanf("%d",&voit.idVoiture);
		}
		
		printf("voulez vous modifier la marque ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" la nouvelle marque de la voiture:");
 		fflush(stdin);
 		scanf("%s",voit.marque);
		}
		
		printf("voulez vous modifier le nom ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf("le nouveau nom de la voiture:");
 		fflush(stdin);
 		scanf("%s",voit.nomVoiture);
		}
		printf("voulez vous modifier la couleur ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" la nouvelle couleur:");
 		scanf("%s",&voit.couleur);
    	}
   		printf("voulez vous modifier le nombre de place ?(o/n)");
   		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf("le nouveau nombre de place:");
 		fflush(stdin);
 		scanf("%d",&voit.nbplaces);
    	}
   		printf("voulez vous modifier le prix du jour ?(o/n)");
   		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" le nouveau prix du jour:");
 		fflush(stdin);
 		scanf("%d",&voit.prixJour);
    	}
   		printf("voulez vous modifier en location ?(o/n)");
   		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf("en location:");
 		fflush(stdin);
 		scanf("%s",voit.EnLocation);
		}
		tv[i]=voit;
		i++;
		trouve=1;
		}}}
realloc(tv,taille*sizeof(voiture));
fclose(v);
if(trouve==0) {printf("aucune voiture de cet id\n");}
else
{FILE*vt=fopen(fichv,"wb+");
for(i=0;i<taille;i++)
	{
		fwrite(&tv[i],sizeof(voiture),1,vt);
	}
fclose(vt);
free(tv);
}}
void SupprimerVoiture(char*fichv)
{voiture voit;
int id,trouve=0,i=0,j=0;
FILE*v=fopen(fichv,"rb");
voiture*tv=(voiture*)malloc(100*sizeof(voiture));
if(!v) {printf("erreur d'ouverture du fichier %s ",fichv);
			exit(-1);}
if(!tv)
{printf("erreur d'allocation du tableau");
exit(-1);
}
if(v!=NULL && tv!=NULL)
{
printf("l'id de la voiture que vous voulez supprimer:");
scanf("%d",&id);
while(fread(&voit,sizeof(voiture),1,v))
{	if(voit.idVoiture!=id)
		{tv[i]=voit;
		i++;}
else trouve=1;
}}
j=i;
realloc(tv,j*sizeof(voiture));
fclose(v);
if(trouve==0) {printf("aucune voiture de cet id\n");}
else{
v=fopen(fichv,"wb+");
for(i=0;i<j;i++)
	{
		fwrite(&tv[i],sizeof(voiture),1,v);
	}
fclose(v);
if(j>0)
 free(tv);
}}
void ListeClients(char*fichc)
 {client cli;
 int i=1;
 FILE*c=fopen(fichc,"rb");
 if(!c) {printf("erreur d'ouverture du fichier %s",fichc);
 		exit(-1);}
 else{
 while(fread(&cli,sizeof(client),1,c)) 
 {
 	printf("     client num %d:\n",i);
	printf("id:%d\n",cli.idClient);
	printf("nom:%s\n",cli.nom);
	printf("prenom:%s \n",cli.prenom);
	printf("cin:%d \n",cli.cin);
	printf("adresse:%s\n",cli.adresse);
	printf("telephone:0%d\n",cli.telephone);
	i++;
 }}
 fclose(c);
 }
void AjouterClient(char*fichc)
{client cli;
FILE*c=fopen(fichc,"ab+");
if(!c) {printf("erreur d'ouverture du fichier %s",fichc);
		exit(-1);}
else{
	printf("l'id du client:");
 	scanf("%d",&cli.idClient);
 	printf("le nom du client:");
 	scanf("%s",cli.nom);
 	printf("le prenom du client:");
 	scanf("%s",cli.prenom);
 	printf("le cin du client:");
 	scanf("%d",&cli.cin);
 	printf("l'adresse du client:");
 	scanf("%s",cli.adresse);
 	printf("telephone du client:");
 	scanf("%d",&cli.telephone);
fwrite(&cli,sizeof(client),1,c);
}
fclose(c);
}
void ModifierClient(char*fichc)
{client cli;
int id,trouve=0,taille=0,i=0;
client*tc=(client*)malloc(100*sizeof(client));
FILE*c=fopen(fichc,"rb");
char choix;
if(!c ){printf("erreur d'ouverture du fichier %s ou d'allocation'",fichc);
			exit(-1);
		 }
if(!tc){printf("erreur d'allocation");
exit(-1);
}
if(c!=NULL && tc!=NULL)
{
printf("l'id du client a modifier :");
scanf("%d",&id);

while(fread(&cli,sizeof(client),1,c))
	{	taille++;
		if(cli.idClient!=id)
		{tc[i]=cli;
		i++;
		}
	else
		{printf("voulez vous modifier l'id ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
		printf("le nouveau id du client:");
		fflush(stdin);
 		scanf("%d",&cli.idClient);
		}
		
		printf("voulez vous modifier le nom ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" le nouveau nom du client:");
 		fflush(stdin);
 		scanf("%s",&cli.nom);
		}
		
		printf("voulez vous modifier le prenom ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf("le nouveau prenom du client:");
 		fflush(stdin);
 		scanf("%s",&cli.prenom);
		}
		
   		printf("voulez vous modifier l'adresse?(o/n)");
   		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf("la nouvelle adresse:");
 		fflush(stdin);
 		scanf("%s",&cli.adresse);
    	}
    	printf("voulez vous modifier le cin?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" le nouveau cin:");
 		fflush(stdin);
 		scanf("%d",&cli.cin);
    	}
   		printf("voulez vous modifier le numero de telephone ?(o/n)");
   		fflush(stdin);
		scanf("%c",&choix);
		if(choix==111||choix==79)
		{
 		printf(" le nouveau numero:");
 		fflush(stdin);
 		scanf("%d",&cli.telephone);
    	}
		tc[i]=cli;
		i++;
		trouve=1;
		}}}
realloc(tc,taille*sizeof(client));
fclose(c);

if(trouve==0) {printf("aucun client de cet id\n");}
else
{FILE*cl=fopen(fichc,"wb+");
for(i=0;i<taille;i++)
	{
		fwrite(&tc[i],sizeof(client),1,cl);
	}
fclose(cl);
free(tc);
}}
void SupprimerClient(char*fichc)
{client cli;
int id,trouve=0,i=0,j=0;
FILE*c=fopen(fichc,"rb");
client*tc=(client*)malloc(100*sizeof(client));
if(!c) {printf("erreur d'ouverture du fichier %s",fichc);
			exit(-1);}
if(!tc){printf("erreur d'allocation ");
exit(-1);
}
if(c!=NULL && tc!=NULL)
{
printf("l'id du client que vous voulez supprimer:");
scanf("%d",&id);
while(fread(&cli,sizeof(client),1,c))
{if(cli.idClient!=id)
		{
		tc[i]=cli;
		i++;
	    }
else trouve=1;
}}
j=i;
realloc(tc,j*sizeof(client));
fclose(c);
if(trouve==0) {printf("aucun client de cet id");}
else{
c=fopen(fichc,"wb+");
for(i=0;i<j;i++)
	{
		fwrite(&tc[i],sizeof(client),1,c);
	}
	fclose(c);
if(j>0)
free(tc);
}}

void  VisualiserContrat(char*fichct)
{contrat ct;
float num;
int trouve=0;
FILE*cnt=fopen(fichct,"rb");
if(!cnt){printf("erreur d'ouverture du fichier %s ",fichct);
		exit(-1);
		}
else{
printf("le numero de contrat :");
scanf("%f",&num);
while(fread(&ct,sizeof(contrat),1,cnt))
{if(ct.numContrat==num)
		{trouve=1;
		printf("   le contrat de numero :%f\n",ct.numContrat);
		printf("id de voiture:%d\n",ct.idVoiture);
		printf("l'id du client:%d\n",ct.idClient);
		printf("date de debut :%d %d %d\n",ct.debut.jour,ct.debut.mois,ct.debut.annee);
		printf("date de fin :%d %d %d\n",ct.fin.jour,ct.fin.mois,ct.fin.annee);
		printf("le cout:%d\n",ct.cout);
		}
}
if(trouve==0) printf("aucun contra de ce numero\n");
}
fclose(cnt);
}

void LouerVoiture(char*fichv,char*fichc,char*fichct)
{client cli;
client nvcli;
voiture voit;
voiture vs;
contrat ct;
int i=0;
int id,trouvec=0,trouvev=0;
FILE*v;
FILE*c;
FILE*cont;
voiture*tv=(voiture*)malloc(100*sizeof(voiture));
v=fopen(fichv,"ab+");
c=fopen(fichc,"ab+");
cont=fopen(fichct,"ab+");
if(!v || !c|| !cont){printf("erreur d'ouverture de fichiers\n");
				exit(-1);
				}
if(!tv)
{printf("erreur d'allocation\n");
exit(-1);
}
printf("\n saisir votre nom:");
scanf("%s",&nvcli.nom);
printf("\n saisir votre prenom:");
scanf("%s",&nvcli.prenom);
fseek(c,0,SEEK_SET);
while(fread(&cli,sizeof(client),1,c) )
{if(!strcmp(cli.nom,nvcli.nom) && !strcmp(cli.prenom,nvcli.prenom))
	{trouvec=1;
	printf("bonjour");
	printf(" donnez les informations sur la voiture souhaite:");
	printf("\n la marque:");
	scanf("%s",vs.marque);
	printf("\n le nom:");
	scanf("%s",vs.nomVoiture);
	printf("\ncouleur:");
	scanf("%s",vs.couleur);
	printf("\n le nombre de places:");
	scanf("%d",&vs.nbplaces);
		fseek(v,0,SEEK_SET);
		while(fread(&voit,sizeof(voiture),1,v) )
		  {
		  	if(!strcmp(voit.marque,vs.marque) && !strcmp(voit.nomVoiture,vs.nomVoiture) && !strcmp(voit.couleur,vs.couleur) && voit.nbplaces==vs.nbplaces)
		  		{trouvev=1;
				  printf("nous avons trouve la voiture que vous voulez");
				if(!strcmp(voit.EnLocation,"oui"))
		  			printf(" mais elle est deja louer\n");
		  		else
		  		  {ct.idVoiture=voit.idVoiture;
		  		  ct.idClient=cli.idClient;
		  		do{
		  		  printf("\n NB:nous acceptons les location du meme mois (mm mois et mm annee de debut et fin de location)");
				  printf("\nla date de debut de location:");
		  		  scanf("%d %d %d",&ct.debut.jour,&ct.debut.mois,&ct.debut.annee);
		  		  printf("la date de fin de location:");
		  		  scanf("%d %d %d",&ct.fin.jour,&ct.fin.mois,&ct.fin.annee);
		  		  ct.cout=(ct.fin.jour-ct.debut.jour)*voit.prixJour;
		  		  if(ct.cout<0) printf("date erronee");
		  	    }while(ct.debut.mois!=ct.fin.mois || ct.debut.annee!=ct.fin.annee ||ct.cout<0);
					printf("numero de contrat:");
		  		  fflush(stdin);
		  		  scanf("%f",&ct.numContrat);
		  		   fwrite(&ct,sizeof(contrat),1,cont);
		  		  printf("vous avez louer la voiture le cout est %d dh \n vous pouvez voir votre contrat (VisualiserContrat)\n",ct.cout);
				strcpy(voit.EnLocation,"oui");
				  }
				  }
				  tv[i]=voit;
					i++;
		  }
	}}
int j=i;
realloc(tv,j*sizeof(voiture));
if(trouvec==0)
{printf("enregistrer d'abord vos informations perssonnel dans le MenuGestionClients\n");
MenuPrincipal(fichv,fichc,fichct);
}
if(trouvev==0) printf("on a pas la voiture que vous chercher\n");
fclose(v);
fclose(c);
fclose(cont);
v=fopen(fichv,"wb+");
	for(i=0;i<j;i++)
		fwrite(&tv[i],sizeof(voiture),1,v);	
fclose(v);
free(tv);	

}

void RetournerVoiture(char*fichv,char*fichct)
{int id;
contrat ct;
voiture voit;
int i=0,n=0,trouve=0,j,c,retourner=0;
FILE *v=fopen(fichv,"rb");
FILE *cnt=fopen(fichct,"rb");
contrat*tct=(contrat*)malloc(100*sizeof(contrat));
voiture*tv=(voiture*)malloc(100*sizeof(voiture));
if(!cnt || !v) {printf("erreur d'ouverture des fichiers  \n");
		exit(-1);
		}
if(!tct || !tv){printf("erreur d'allocation\n");
		exit(-1);
		}
		
printf("l'id de la voiture retourner:");
scanf("%d",&id);
while(fread(&voit,sizeof(voiture),1,v))
			{
			if(voit.idVoiture==id)
				{trouve=1;
				if(!strcmp(voit.EnLocation,"non")) {printf("erreur la voiture n'a pas etait en location \n ");
				break;}
				if(!strcmp(voit.EnLocation,"oui"))
					{retourner=1;
					strcpy(voit.EnLocation,"non");
							}
			}
			tv[n]=voit;
				n++;}

if(retourner==1){
while(fread(&ct,sizeof(contrat),1,cnt))
							{
					if(ct.idVoiture!=id)
						{
						tct[i]=ct;
						i++;}}}
 j=i; 
 c=n;
realloc(tct,j*sizeof(contrat));
realloc(tv,c*sizeof(voiture));						
fclose(v);
fclose(cnt);
if(trouve==0) printf("aucune voiture de cet id\n");
if(trouve==1)
{
cnt=fopen(fichct,"wb+");
for(i=0;i<j;i++)
	{
	fwrite(&tct[i],sizeof(contrat),1,cnt);
	}
   fclose(cnt);
	free(tct);
v=fopen(fichv,"wb+");
for(i=0;i<c;i++)
	{
	fwrite(&tv[i],sizeof(voiture),1,v);
	}
        fclose(v);
        	free(tv);
} 
}

void ModifierContrat(char*fichv,char*fichct)
{contrat ct;
voiture voit;
float num;
int i=0,modif=0;
char choix;
FILE*cnt=fopen(fichct,"rb");
FILE*v=fopen(fichv,"rb");
contrat *tct=(contrat*)malloc(100*sizeof(contrat));
if(!cnt || !v ) {printf("erreur d'ouverture des fichiers",fichct);
		exit(-1);
		}
if(!tct){printf("erreur d'allocation");
exit(-1);
}
else{
printf("le numero de contrat que vous voulez modifier:");
scanf("%f",&num);
while(fread(&ct,sizeof(contrat),1,cnt))
	{
	if(ct.numContrat==num)
	{	do{	
		printf("voulez vous modifier la date de debut ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		 if(choix==111||choix==79)
			{
			printf("la nouvelle date du debut:");
			fflush(stdin);
			scanf("%d %d %d",&ct.debut.jour,&ct.debut.mois,&ct.debut.annee);
 			}
		printf("voulez vous modifier la date de fin ?(o/n)");
		fflush(stdin);
		scanf("%c",&choix);
		 if(choix==111||choix==79)
			{
			printf("la nouvelle date de fin:");
			fflush(stdin);
 			scanf("%d %d %d",&ct.fin.jour,&ct.fin.mois,&ct.fin.annee);
			}
			
			while(fread(&voit,sizeof(voiture),1,v))
			{if(voit.idVoiture==ct.idVoiture)
				ct.cout=(ct.fin.jour-ct.debut.jour)*voit.prixJour;
			}
			}while(ct.debut.mois!=ct.fin.mois || ct.debut.annee!=ct.fin.annee ||ct.cout<0);
	modif=1;}
	tct[i]=ct;
	i++;	
	}}
int j=i;
realloc(tct,j*sizeof(client));
fclose(cnt);
fclose(v);
if(modif==0) {printf("aucun contrat de ce numero \n");}
else
{FILE*cnt2=fopen(fichct,"wb+");
for(i=0;i<j;i++)
	{
		fwrite(&tct[i],sizeof(client),1,cnt2);
	}
fclose(cnt2);
free(tct);
}}

void SupprimerContrat(char*fichv,char*fichct)
{float num;
contrat ct;
voiture voit;
int j,i=0,supp=0,trouve=0;
contrat*tct=(contrat*)malloc(100*sizeof(contrat));
FILE *v=fopen(fichv,"rb");
FILE *cnt=fopen(fichct,"rb");
if(!cnt || !v ) {printf("erreur d'ouverture du fichiers\n");
		exit(-1);
		}
if(!tct){printf("erreur d'allocation");
			exit(-1);
		}
printf("le numero de contrat a supprimer");
scanf("%f",&num);
while(fread(&ct,sizeof(contrat),1,cnt))
{
if(ct.numContrat==num)
	{trouve=1;
	while(fread(&voit,sizeof(voiture),1,v))
		{if(voit.idVoiture==ct.idVoiture)
			{
			if(!strcmp(voit.EnLocation,"oui"))
				{
				printf("la voiture est en cours de location vous pouvez pas supprimer ce contrat");
						tct[i]=ct;
						i++;
				}
			else supp=1;
			}
		}
	}
else{
	tct[i]=ct;
		i++;
	}
}
j=i;
realloc(tct,j*sizeof(contrat));
fclose(v);
fclose(cnt);
if(trouve==0){printf("aucun contrat de ce num \n");}
if(supp==1) {printf("le contrat est bien supprimer\n");}
cnt=fopen(fichct,"wb+");
for(i=0;i<j;i++)
	{
		fwrite(&tct[i],sizeof(contrat),1,cnt);
	}
	fclose(cnt);
if(j>0)
free(tct);
}

