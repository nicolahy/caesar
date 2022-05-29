#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defines.h"
#include "functions_prototypes.h"

char shiftLetter(char letter, int encryptionKey) {

  if(letter >= 'a'&& letter <= 'z') {
    letter = letter - 'a';
    letter = (letter + encryptionKey) % 26;
    if(letter < 0) {
      letter = letter + 26;
    }
    return (letter + 'a');
  } 
  else if (letter >= 'A' && letter <= 'Z') {
    letter = letter - 'A';
    letter = (letter + encryptionKey) % 26;
    if(letter < 0) {
      letter = letter + 26;
    }
    return (letter + 'A');
  } 
  else {
    return letter;
  }
}

void displayMessage(char *message, int typeMessage) {
  switch(typeMessage) {
    case TYPE_MESSAGE_ERROR: fprintf(stderr,"%s\n", message); exit(EXIT_FAILURE); break;
    case TYPE_MESSAGE_NORMAL: fprintf(stdout,"%s\n", message); exit(EXIT_SUCCESS); break;
    default: fprintf(stdout,"%s\n", message); exit(EXIT_SUCCESS); break;
  }
}
