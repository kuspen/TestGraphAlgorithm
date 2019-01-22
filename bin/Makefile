libGraph: 
	g++ -shared -install_name $(abspath .)/libGraph.dylib ../src/Node.o ../src/Graph.o -o libGraph.dylib

Node.o: ../src/Node.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/Node.cpp -o ../Node.o

Graph.o:../src/Graph.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/Graph.cpp -o ../Graph.o
