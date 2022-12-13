all: mylib.o 
	gcc -o main_test.out mylib.o main_test.c

mylib.o: mylib/mylib.c
	gcc -o mylib.o -c mylib/mylib.c

test:
	gcc -o mylib.o -c mylib/mylib.c
	gcc -o main_test.out main_test.c mylib.o
	./main_test.out

time: 
	gcc -o mylib.o -c mylib/mylib.c  
	gcc -o main_b_time.out main_b_time.c mylib.o 
	./main_b_time.out;

space:
	gcc -o mylib.o -c mylib/mylib.c   
	gcc -o main_b_space.out main_b_space.c mylib.o
	./main_b_space.out;
	
clear: 
	rm -rf *.out
	rm -rf *.o
