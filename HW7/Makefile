OBJ_PATH=./lib/obj/
SRC_PATH=./lib/src/

all: lib/libcalc.a
	gcc -o prog main.c -L./lib -lcalc

lib/libcalc.a: $(OBJ_PATH)main.o $(OBJ_PATH)add.o $(OBJ_PATH)sub.o $(OBJ_PATH)mul.o $(OBJ_PATH)div.o
	ar r lib/libcalc.a $(OBJ_PATH)*.o

$(OBJ_PATH)main.o: $(SRC_PATH)main.c
	gcc -c $(SRC_PATH)main.c
	mv main.o $(OBJ_PATH)

$(OBJ_PATH)add.o: $(SRC_PATH)add.c
	gcc -c $(SRC_PATH)add.c
	mv add.o $(OBJ_PATH)

$(OBJ_PATH)sub.o: $(SRC_PATH)sub.c
	gcc -c $(SRC_PATH)sub.c
	mv sub.o $(OBJ_PATH)

$(OBJ_PATH)mul.o: $(SRC_PATH)mul.c
	gcc -c $(SRC_PATH)mul.c
	mv mul.o $(OBJ_PATH)

$(OBJ_PATH)div.o: $(SRC_PATH)div.c
	gcc -c $(SRC_PATH)div.c
	mv div.o $(OBJ_PATH)

clean:
	rm $(OBJ_PATH)*.o
	rm prog
