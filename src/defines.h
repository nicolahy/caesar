#ifndef _DEFINES_H
#define _DEFINES_H

/**
 * Number of letters for the alphabet to be encrypted/decrypted
 */
#define ALPHABET_LENGTH 26;
/**
 * Types of message : error
 */
#define TYPE_MESSAGE_ERROR -1
/**
 * Types of message : normal
 */
#define TYPE_MESSAGE_NORMAL 0
/**
 * List of messages : error - arguments
 */
#define ERROR_MESSAGE_NUMBER_ARGUMENTS "[KO] The number of arguments is incorrect. Please check the command-line."
/**
 * List of messages : error - files
 */
#define ERROR_MESSAGE_FILES "[KO] An error occurred with the use of the files. Check the source and/or destination path."
/**
 * List of messages : error - encryption key
 */
#define ERROR_MESSAGE_ENCRYPTION_KEY "[KO] Using a zero value encryption key has no effect, please enter a number greater than zero."
/**
 * List of messages : success - done
 */
#define SUCCESS_MESSAGE_DONE "[OK] Caesar encryption successfully completed."

#endif