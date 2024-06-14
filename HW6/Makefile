all: homework

homework: obj/main.o obj/menu.o obj/subscriber.o
	gcc -g -o homework obj/subscriber.o obj/menu.o obj/main.o

debug: obj/main.o obj/menu.o obj/subscriber.o
	gcc obj/main.o obj/menu.o obj/subscriber.o -o debug

obj/main.o: src/main.c
	gcc -c -g src/main.c 
	mv main.o obj

obj/menu.o: src/menu.c
	gcc -c -g src/menu.c 
	mv menu.o obj

obj/subscriber.o: src/subscriber.c
	gcc -c -g src/subscriber.c
	mv subscriber.o obj
	
clean:
	rm obj/*.o
	rm homework