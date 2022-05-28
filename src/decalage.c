#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decalage.h"

char decale_lettre(char c,int k) {

  if(c>='a'&&c<='z') { /* Si c'est une lettre minuscule */
    c=c-'a';
    c=(c+k)%26;
    if(c<0)
      c=c+26;

    return (c+'a');
  }

  else if (c>='A'&&c<='Z') { /* Si c'est une lettre majuscule */
    c=c-'A';
    c=(c+k)%26;
    if(c<0)
      c=c+26;

    return (c+'A');
  }
  else  /* Si c'est un chiffre, une lettre avec accent etc... laisser le caractere comme tel */
    return c;

}

void erreur(char *s) { /* message d'erreur si l'utilisateur ne rentre pas une ligne de commande correcte */

  fprintf(stderr,"%s",s);
  exit(EXIT_FAILURE);
}
