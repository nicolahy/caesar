#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decalage.h"

int main(int argc,char *argv[]) {

  if(argc!=4) /* Si le nombre d'arguments different de 4, rappeler a l'ordre l'utilisateur */
    erreur("\n<--------------------UTILISATION A PARTIR DU DOSSIER PRINCIPAL:-------------------->\n./bin/[nom_executable] [fichier_source] [fichier_destination] [cle_de_cryptage]\n<---------------------------------------------------------------------------------->\n\n");

  int cle_de_cryptage=atoi(argv[3]); /* Conversion de la chaine de caractere qui constitue le 4eme argument 
					en un entier exploitable */;

  FILE* destination=fopen(argv[2],"w+"); /* ouverture du fichier de destination, mode lecture et ecriture, 
					   pointeur au debut, creation du fichier si non-existant,
					   effacement de son contenu sinon */
					  
  FILE* pointeur=fopen(argv[1],"r"); /* ouverture du fichier source, mode lecture seule, pointeur au debut,
					le fichier doit exister */
  int c=0; /* Caractere qui sera lu par la fonction fgetc() */

  char tmp; /* Servira a stocker le caractere modifie (ou non) par la fonction decale_lettre() */

  if(pointeur!=NULL&&destination!=NULL) { /* Si l'ouverture des fichiers source et destination n'a pas echoue */
   
    while((c=fgetc(pointeur))!=EOF) { /* Lecture du caractere du fichier source, continuer tant 
					 que fgetc n'a pas retourne EOF (fin de fichier) */

      tmp=decale_lettre(c,cle_de_cryptage); /* Modifier le caractere (ou non s'il possede un accent,
					       si c'est un chiffre, un caractere special...) 
					       en tenant compte de la cle de cryptage */
      fprintf(destination,"%c",tmp); /* Ecrire ce caractere dans le fichier de destination */
    }
  }
  else if(pointeur==NULL||destination==NULL) /* Si le(s) chemin d'acces du(es) fichier(s) source et/ou 
						destination est(sont) mal renseigne(s) */
    erreur("\nIMPOSSIBLE D'OUVRIR LE(S) fICHIER(S) SOURCE ET/OU DESTINATION :-(\nVERIFIEZ LE(S) CHEMIN(S) D'ACCES ET RECOMMENCEZ.\n\n");

  printf("\nL'OPERATION S'EST DEROULEE AVEC SUCCES :-)\n\n");

  fclose(pointeur); /* Fermeture du fichier source */
  fclose(destination); /* Fermeture du fichier de destination */

  return 0;
}
