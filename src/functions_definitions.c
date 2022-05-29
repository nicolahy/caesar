#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defines.h"
#include "functions_prototypes.h"

/**
 * Shifts the letter in the alphabet according to the encryption key given in parameter. 
 * The formula used is: 
 * C(x) = (x + k) (mod n),
 * where x = rank of the letter to be encrypted, n = length of the alphabet, k = encryption key
 */
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

/**
 * Display an error or success message to the user. Stop the program if necessary.
 */
void displayMessage(char *message, int typeMessage) {
  switch(typeMessage) {
    case TYPE_MESSAGE_ERROR: fprintf(stderr,"%s\n", message); exit(EXIT_FAILURE); break;
    case TYPE_MESSAGE_NORMAL: fprintf(stdout,"%s\n", message); break;
    default: fprintf(stdout,"%s\n", message); break;
  }
}
