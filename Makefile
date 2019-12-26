all: dsa191a1

DEFS = -DUSE_SOME_DEF

dsa191a1: dbLib.o main.o processData.o
	g++ main.o dbLib.o processData.o -std=c++11 -o -g dsa191a1 $(DEFS)
main.o: main.cpp dsaLib.h dbLib.h processData.h
	g++ -g -c main.cpp -std=c++11 $(DEFS)
dbLib.o: dbLib.cpp dbLib.h dsaLib.h
	g++ -g -c dbLib.cpp -std=c++11 $(DEFS)
processData.o: processData.cpp dsaLib.h dbLib.h processData.h
	g++ -g -c processData.cpp -std=c++11 $(DEFS)

clean:
	rm *.o dsa191a1
