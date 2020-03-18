main: fileReader.o main.o client.o vehicle.o model.o graph.o heuristic.o swap.o twoOpt.o reinsertion.o util.o localSearch.o
	g++ main.o fileReader.o client.o vehicle.o model.o graph.o heuristic.o swap.o twoOpt.o reinsertion.o util.o localSearch.o -o main

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

swap.o: src/swap.cpp includes/swap.h
	g++ -c -g src/swap.cpp

twoOpt.o: src/twoOpt.cpp includes/twoOpt.h
	g++ -c -g src/twoOpt.cpp

reinsertion.o: src/reinsertion.cpp includes/reinsertion.h
	g++ -c -g src/reinsertion.cpp

util.o: src/util.cpp includes/util.h
	g++ -c -g src/util.cpp

localSearch.o: src/localSearch.cpp includes/localSearch.h
	g++ -c -g src/localSearch.cpp

clean:
	rm -f *.o main 