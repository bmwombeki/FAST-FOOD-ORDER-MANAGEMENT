bmwomb2project4: first.o second.o third.o
         gcc -o bmwomb2project4 first.o second.o third.o

first.o: first.c Queue.h
         gcc -c first.c

second.o: second.c Queue.h
         gcc -c second.c

third.o: third.c Queue.h
         gcc -c third.c

clean:
	 rm first.o second.o third.o bmwomb2project4
