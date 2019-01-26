#pragma once
#include "Graph.h"

class DFS {
public:
    DFS(Graph *graph);
    ~DFS();

    void solve();

private:
    Graph *mGraph;

};
