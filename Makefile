main: fileReader.o main.o client.o vehicle.o model.o graph.o heuristic.o
	g++ main.o fileReader.o client.o vehicle.o model.o graph.o heuristic.o -o main

main.o: src/main.cpp
	g++ -c -g src/main.cpp

fileReader.o: src/fileReader.cpp includes/fileReader.h
	g++ -c -g src/fileReader.cpp

client.o: src/client.cpp includes/client.h
	g++ -c -g src/client.cpp

vehicle.o: src/vehicle.cpp includes/vehicle.h
	g++ -c -g src/vehicle.cpp

model.o: src/model.cpp includes/model.h	
	g++ -c -g src/model.cpp

graph.o: src/graph.cpp includes/graph.h
	g++ -c -g src/graph.cpp

heuristic.o: src/heuristic.cpp includes/heuristic.h 
	g++ -c -g src/heuristic.cpp

clean:
	rm -f *.o main 