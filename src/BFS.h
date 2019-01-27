#pragma once
#include "Graph.h"

class BFS {
public:
    BFS(Graph graph);
    ~BFS();

    void solve();

private:
    Graph mGraph;

};
