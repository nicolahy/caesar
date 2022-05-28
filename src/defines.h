#ifndef _DEFINES_H
#define _DEFINES_H

/* type of message */
#define TYPE_MESSAGE_ERROR -1
#define TYPE_MESSAGE_NORMAL 0

/* messages */
#define ERROR_MESSAGE_NUMBER_ARGUMENTS "[KO] The number of arguments is incorrect. Please check the command-line."
#define ERROR_MESSAGE_FILES "[KO] An error occurred with the use of the files. Check the source and/or destination path."
#define ERROR_MESSAGE_ENCRYPTION_KEY "[KO] Using a zero value encryption key has no effect, please enter a number greater than zero."
#define SUCCESS_MESSAGE_DONE "[OK] Caesar encryption successfully completed."

#endif