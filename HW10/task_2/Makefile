O=./obj/
S=./src/

all: main.o childhood.o beautyPrint.o
	gcc -o main $(O)main.o $(O)childhood.o $(O)beautyPrint.o 

main.o: $(S)main.c
	gcc -c $(S)main.c
	mv main.o $(O)

childhood.o: $(S)childhood.c
	gcc -c $(S)childhood.c
	mv childhood.o $(O)	

beautyPrint.o: $(S)beautyPrint.c
	gcc -c $(S)beautyPrint.c
	mv beautyPrint.o $(O)

clean:
	rm $(O)*.o