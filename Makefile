partie1: main1
	./main1 seq01.txt seq02.t

main1: main1.o sequence.o distance.o
	gcc -Wall -o main1 main1.o sequence.o distance.o

main1.o: main1.c
	gcc -Wall -c main1.c

sequence.o: sequence.c sequence.h
	gcc -Wall -c -g sequence.c sequence.h

distance.o: distance.c distance.h
	gcc -Wall -c distance.c distance.h


clean:
	rm -rf *.o
	rm -rf main1
	rm -rf sequence.h.gch distance.h.gch
	ls -l


ZIPNAME=PITTIS_DOSSANTOS
zip:
	rm -rf ${ZIPNAME}
	mkdir ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp Makefile ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
	ls -l ${ZIPNAME}