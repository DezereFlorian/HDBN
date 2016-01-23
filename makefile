hdbn : main.o engine.o 
	@gcc -o hdbn engine.o main.o
	
main.o : main.c
	@gcc -c main.c -Wall
       
engine.o : engine.c header.h
	@gcc -c engine.c -Wall
       
clean :
	rm *.o *~ 
