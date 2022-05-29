#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"
#include "functions_prototypes.h"

int main(int argc,char *argv[]) {

  if(argc != 4) {
    displayMessage(ERROR_MESSAGE_NUMBER_ARGUMENTS, TYPE_MESSAGE_ERROR);
  }

  int encryptionKey = atoi(argv[3]); /* Conversion of the string which constitutes the 4th argument into a usable integer */;

  if(encryptionKey == 0) {
    displayMessage(ERROR_MESSAGE_ENCRYPTION_KEY, TYPE_MESSAGE_ERROR);
  }

  FILE *source = fopen(argv[1],"r"); /* The source file must exist */
  FILE *destination = fopen(argv[2],"w+");

  if(source == NULL || destination == NULL) {
    displayMessage(ERROR_MESSAGE_FILES, TYPE_MESSAGE_ERROR);
  }

  int c = 0; /* Character read by fgetc() */

  while((c = fgetc(source)) != EOF) {
    fprintf(destination,"%c", shiftLetter(c, encryptionKey));
  }

  fclose(source);
  fclose(destination);

  displayMessage(SUCCESS_MESSAGE_DONE, TYPE_MESSAGE_NORMAL);

  return 0;
}
