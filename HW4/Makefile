all: homework

homework: main.o menu.o subscriber.o
	gcc main.o menu.o subscriber.o -o homework

main.o: main.c
	gcc -c main.c 

menu.o: menu.c
	gcc -c menu.c 

subscriber.o: subscriber.c
	gcc -c subscriber.c
	
clean:
	rm *.o
	rm homework