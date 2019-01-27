libGraph: Node.o Graph.o DFS.o BFS.o
	g++ -shared -install_name $(abspath .)/libGraph.dylib ../src/Node.o ../src/Graph.o ../src/DFS.o ../src/BFS.o -o libGraph.dylib

Node.o:../src/Node.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/Node.cpp -o ../src/Node.o

Graph.o:../src/Graph.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/Graph.cpp -o ../src/Graph.o

DFS.o:../src/DFS.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/DFS.cpp -o ../src/DFS.o

BFS.o:../src/BFS.cpp
	g++ -std=c++11 -O2 -Wall -fPIC -c ../src/BFS.cpp -o ../src/BFS.o