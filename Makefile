main: fileReader.o main.o demands.o
	g++ main.o fileReader.o demands.o -o main

main.o: main.cpp
	g++ -c -g main.cpp

fileReader.o: fileReader.cpp includes/fileReader.h
	g++ -c -g fileReader.cpp

demands.o: demands.cpp includes/demands.h
	g++ -c -g demands.cpp

clean:
	rm -f *.o main 