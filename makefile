all: client1 server1
client1: client1.o
	gcc client1.o -o client1
server1: server1.o
	gcc server1.o -o server1
client1.o: client1.c
	gcc -ansi -pedantic -g -c -o client1.o client1.c
server1.o: server1.c
	gcc -ansi -pedantic -g -c -o server1.o server1.c

clean:
	rm -rf *.o server1 client1