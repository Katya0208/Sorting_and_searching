all: run

full: client.o table.o func.o
	gcc client.o table.o func.o -o full

client.o: client.c
	gcc -c client.c

table.o: table.c
	gcc -c table.c

func.o: func.c
	gcc -c func.c

run: full
	./full

clean:
	rm -rf *.o full