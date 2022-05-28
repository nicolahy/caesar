CC=gcc
CFLAGS=-Wall -ansi
OBJ=main.o functions_definitions.o

all:
	make crypt
	make decrypt

crypt:  $(OBJ)
	$(CC) -o crypt $(OBJ) $(CFLAGS)
	mv crypt ./bin/
	mv *.o ./obj/
	@echo "[OK] THE EXECUTABLE <CRYPT> HAS BEEN GENERATED IN THE ./BIN/ DIRECTORY"

decrypt:$(OBJ)
	$(CC) -o decrypt $(OBJ) $(CFLAGS)
	mv decrypt ./bin/
	mv *.o ./obj/
	@echo "[OK] THE EXECUTABLE <DECRYPT> HAS BEEN GENERATED IN THE ./BIN/ DIRECTORY"

main.o: ./src/main.c ./src/defines.h ./src/functions_prototypes.h
	$(CC) -c ./src/main.c $(CFLAGS)

functions_definitions.o: ./src/functions_definitions.c ./src/functions_prototypes.h
	$(CC) -c ./src/functions_definitions.c $(CFLAGS)

clean:
	rm -f ./bin/* ./obj/*.o
	@echo "[OK] THE PROJECT HAS BEEN CLEANED UP !"
