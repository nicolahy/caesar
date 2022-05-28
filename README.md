# PROJET CEASAR

### Summary
I) Introduction
II) Creation of executables
III) Use
IV) Examples
V) Deleting
VI) Memory management
VII) Automatic documentation
VIII) Known weaknesses

## I) Introduction
The Cesar cipher, or shift cipher, is one of the oldest cryptographic methods.
The original message undergoes alphabetically a shift chosen by its author, letter by letter.
This system is part of the foundations of cryptography and I propose here to test it.

II) Creation of executables
Unzip the archive and use the "make" command in the main folder.

Details about the project directories :

a) bin/ : contains the executables created after the compilation.
b) data/ : contains a file that will be used as an example for a test.
c) doc/ : The files used for automatic documentation.
d) obj/ : contains all the object files generated during compilation.
e) src/ : contains the source code of the project divided into modules.

## III) Use
In the command line type the following line wWe suppose that you are in the main folder) :

```console
foo@bla:~$ ./bin/[executable_name] [source_file] [destination_file] [encryption_key]
```

- Note 1: Pay attention to the order of the arguments.
- Note 2: Pay attention to the path of the files.
- Note 3: The destination file may not exist. If a destination file has the same path as the source file, then the source file will be overwritten.
- Note 4: In the case of decryption, the encryption key used by the sender must of course be revealed to the receiver of the message.
          It is then enough to change the sign of the encryption key given by the the sender to decrypt the concerned file.

## IV) Examples
From the main folder:

```console
foo@bla:~$ ./bin/crypt ./data/test.txt ./data/result.txt 1
```
=> _"Shift of +1 letter"._

```console
foo@bla:~$ ./bin/decrypt ./data/test.txt ./data/result.txt -1
```
=> _"Shift of -1 letter"._

## V) Deletion

From the main folder, type "make clean".
The object files of obj/ and the executables of bin/ will be deleted.

## VI) Memory management

Use the memory analyzer valgrind to make sure that there are no memory leaks.
memory leaks.
You must have taken care to have fclose() in the program when you have finished using a
using a file after opening it with fopen().

Tests performed with the following commands from the bin/ folder:
> valgrind ./bin/crypt ./data/test.txt ./data/result.txt 1
then
> valgrind ./decrypt ./data/test.txt ./data/result.txt 1

Results obtained for each of the previous lines :
```console
total heap usage: 2 allocs, 2 frees, 704 bytes allocated
All heap blocks were freed -- no leaks are possible
```

## VII) Automatic documentation

I used the Doxygen tool, automatic documentation generator.
It is a standard tool to make "clean" projects on the Web.

To view the documentation created from the main folder :

```console
foo@bla:~$ [internet_browser_name] doc/html/index.html then browse the tabs.
```

The procedure that has been followed :

- Download and installation of Doxygen. 
```console
foo@bla:~$ sudo apt-get install doxygen
```

- Command line that will generate a configuration file:
```console
foo@bla:~$ doxygen -g
```
- Open the Doxyfile with a text editor and at the line EXTRACT_ALL replace **NO** by **YES**.
- Final command line from main directory : (2 directories will be created)
```console
foo@bla:~$ doxygen Doxyfile
```

## VIII) Known weaknesses
See Chapter III, Note 3.