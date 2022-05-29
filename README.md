# PROJET CAESAR

## On which operating system can I use it ?
<img alt="linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>

### Summary
1. Introduction
2. Creation of executables
3. Use
4. Examples
5. Deleting
6. Memory management
7. Automatic documentation
8. Known weaknesses

## 1. Introduction
The Caesar cipher, or shift cipher, is one of the oldest cryptographic methods.
The original message undergoes alphabetically a shift chosen by its author, letter by letter.
This system is part of the foundations of cryptography and I propose here to test it.

## 2. Creation of executables
Unzip the archive and use the "make" command in the main directory.

Details about the project directories :

* bin/ : contains the executables created after the compilation.
* data/ : contains a file that will be used as an example for a test.
* doc/ : The files used for automatic documentation.
* obj/ : contains all the object files generated during compilation.
* src/ : contains the source code of the project divided into modules.

## 3. Use
In the command line type the following line. We suppose that you are in the main directory) :

```console
foo@bla:~$ ./bin/[executable_name] [source_file] [destination_file] [encryption_key]
```

- Note #1: Pay attention to the order of the arguments.
- Note #2: Pay attention to the path of the files.
- Note #3: The destination file may not exist. If a destination file has the same path as the source file, then the source file will be overwritten.
- Note #4: In the case of decryption, the encryption key used by the sender must of course be revealed to the receiver of the message.
  It is then enough to change the sign of the encryption key given by the the sender to decrypt the concerned file.

## 4. Examples
From the main directory :

```console
foo@bla:~$ ./bin/crypt ./data/test.txt ./data/result.txt 1
```
=> _"Shift of +1 letter"._

```console
foo@bla:~$ ./bin/decrypt ./data/test.txt ./data/result.txt -1
```
=> _"Shift of -1 letter"._

## 5. Deletion

From the main directory, type :

```console
foo@bla:~$ make clean
```

The object files of obj/ and the executables of bin/ will be deleted.

## 6. Memory management

Use the memory analyzer valgrind to make sure that there are no memory leaks.
memory leaks.
You must have taken care to have fclose() in the program when you have finished using a
using a file after opening it with fopen().

Tests performed with the following commands from the main directory:
```console
foo@bla:~$ valgrind --leak-check=full --show-leak-kinds=all ./bin/crypt ./data/test.txt ./data/result.txt 1
```
then
```console
foo@bla:~$ valgrind --leak-check=full --show-leak-kinds=all ./bin/decrypt ./data/test.txt ./data/result.txt 1
```

Results obtained for each of the previous lines :
```console
==6609== HEAP SUMMARY:
==6609==   in use at exit: 0 bytes in 0 blocks
==6609==   total heap usage: 5 allocs, 5 frees, 10,160 bytes allocated
==6609== 
==6609== All heap blocks were freed -- no leaks are possible
```

## 7. Automatic documentation

I used the Doxygen tool, automatic documentation generator.
It is a standard tool to make "clean" projects on the Web.

The procedure that has been followed :

- Download and installation of Doxygen.
```console
foo@bla:~$ sudo apt-get install doxygen
```

- Command line that will generate a configuration file in the doc/ directory :
```console
foo@bla:~$ doxygen -g
```
- Open the Doxyfile with a text editor and make modifications (directory to browse etc..).
- Final command line from main directory : (2 directories will be created)
```console
foo@bla:~$ doxygen Doxyfile
```

To view the documentation created from the main directory :
```console
foo@bla:~$ [internet_browser_name] doc/html/index.html then browse the tabs.
```

## VIII) Known weaknesses
See Chapter 3, Note #3.