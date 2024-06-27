SRC_PATH=./src/
OBJ_PATH=./obj/

all: $(OBJ_PATH)main.o $(OBJ_PATH)executor.o
	gcc -o interpreter $(OBJ_PATH)main.o $(OBJ_PATH)executor.o

$(OBJ_PATH)main.o: $(SRC_PATH)main.c
	gcc -c $(SRC_PATH)main.c
	mv main.o $(OBJ_PATH)

$(OBJ_PATH)executor.o: $(SRC_PATH)executor.c
	gcc -c $(SRC_PATH)executor.c
	mv executor.o $(OBJ_PATH)

clean:
	rm $(OBJ_PATH)*.o
	rm interpreter