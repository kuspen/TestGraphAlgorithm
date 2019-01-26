#include <iostream>
#include <vector>

#include "../src/define.h"
#include "../src/Graph.h"
#include "../src/Node.h"

#include "../src/DFS.h"

const int g_xSize = 10;
const int g_ySize = 10;

int g_map[g_ySize][g_xSize] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
{ 0, 0, 0, 2, 0, 2, 0, 0, 2, 0},
{ 0, 0, 0, 2, 2, 2, 0, 0, 2, 0},
{ 2, 2, 0, 2, 2, 2, 0, 0, 2, 0},
{ 0, 0, 0, 2, 0, 2, 2, 2, 2, 0},
{ 0, 0, 0, 2, 0, 0, 0, 2, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 2, 0, 0, 2, 0}
};

int main() {

    std::vector<std::vector<int> > map;
    map.assign(g_ySize, std::vector<int>(g_xSize, 0));

    for(int y = 0; y < g_ySize; y++) {
        for(int x = 0; x < g_xSize; x++) {
            map[y][x] = g_map[y][x];
        }
    }

    Graph graph(g_xSize, g_ySize, map);
    graph.SetStartNode(0, 9);
    graph.SetEndNode(6, 4);
    graph.ShowGraph();

    DFS dfs(&graph);
    dfs.solve();

#if 0
    std::cout << "adjacent node\n";
    for(int y = 0; y < g_ySize; y++) {
        for(int x = 0; x < g_xSize; x++) {
            std::cout << "x = " << x << " y = " << y << "\n";
            Node *node = graph.GetNodeByIndex(x, y);
            std::vector<Node*> adjacentNodes;
            node->GetAdjacentNode(adjacentNodes);

            for(auto itr=adjacentNodes.begin(); itr != adjacentNodes.end(); itr++) {
                std::cout << (*itr)->GetXIndex() << " " << (*itr)->GetYIndex() << "\n";
            }

        }
    }
#endif

    return 0;
}