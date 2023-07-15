all: main.o Quicksort.o Heapsort.o
	g++ -g main.o Quicksort.o Heapsort.o -o main

main.o: main.cpp Quicksort.cpp Quicksort.h Heapsort.cpp Heapsort.h
	g++ -c main.cpp

Quicksort.o: Quicksort.cpp Quicksort.h
	g++ -c Quicksort.cpp

Heapsort.o: Heapsort.cpp Heapsort.h
	g++ -c Heapsort.cpp

clean:
	rm *.o
	rm main

run: all main
	./main
