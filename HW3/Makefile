all: task_1.o task_2.o task_3.o task_4.o

task_1.o: task_1_src/main.c
	gcc task_1_src/main.c -o task_1.o
	
task_2.o: task_2_src/main.c
	gcc task_2_src/main.c -o task_2.o
	
task_3.o: task_3_src/main.c
	gcc task_3_src/main.c -o task_3.o
	
task_4.o: task_4_src/main.c task_4_src/stringProcessing.c
	gcc task_4_src/main.c task_4_src/stringProcessing.c -o task_4.o
