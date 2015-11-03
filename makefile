main: dictionary.o main.o
	g++ dictionary.o main.o -o main

dictionary.o: dictionary.h dictionary.cpp
	g++ -c dictionary.cpp

main.o: main.cpp dictionary.h
	g++ -c main.cpp

clean:
	rm main dictionary.o main.o
