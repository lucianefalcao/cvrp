main: fileReader.o main.o client.o vehicle.o
	g++ main.o fileReader.o client.o vehicle.o -o main

main.o: src/main.cpp
	g++ -c -g src/main.cpp

fileReader.o: src/fileReader.cpp includes/fileReader.h
	g++ -c -g src/fileReader.cpp

client.o: src/client.cpp includes/client.h
	g++ -c -g src/client.cpp

vehicle.o: src/vehicle.cpp includes/vehicle.h
	g++ -c -g src/vehicle.cpp

clean:
	rm -f *.o main 