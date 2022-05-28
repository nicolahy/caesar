CC=gcc
CFLAGS=-Wall -ansi
OBJ=main.o decalage.o

all:
	make crypt
	make decrypt

crypt:  $(OBJ)
	$(CC) -o crypt $(OBJ) $(CFLAGS)
	mv crypt bin/
	mv *.o obj/
	@echo "\nGENERATION DE L'EXECUTABLE <CRYPT> OK..."
	@echo "---> IL SE TROUVE DANS LE REPERTOIRE BIN/\n"

decrypt:$(OBJ)
	$(CC) -o decrypt $(OBJ) $(CFLAGS)
	mv decrypt bin/
	mv *.o obj/
	@echo "\nGENERATION DE L'EXECUTABLE <DECRYPT> OK..."
	@echo "---> IL SE TROUVE DANS LE REPERTOIRE BIN/\n"

main.o: src/main.c src/decalage.h
	$(CC) -c src/main.c $(CFLAGS)

decalage.o: ./src/decalage.c ./src/decalage.h
	$(CC) -c src/decalage.c $(CFLAGS)

clean:
	rm obj/*.o
	rm bin/crypt bin/decrypt
	@echo "\nLES FICHIERS GENERES PRECEDEMMENT ONT BIEN ETE SUPPRIMES...\n"
