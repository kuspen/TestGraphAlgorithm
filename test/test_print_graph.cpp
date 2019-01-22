#include <iostream>
#include <vector>

#include "../src/define.h"
#include "../src/Graph.h"

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
{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0}
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
    graph.ShowGraph();


    return 0;
}