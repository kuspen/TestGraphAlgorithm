#include <vector>

#include "Node.h"

class Graph {
public:
    Graph(int xSize, int ySize, std::vector<std::vector<int>> graphInfo);
    ~Graph();

    void SetNode(Node *node) { mNodes.push_back(node); }


private:
    int mXSize;
    int mYSize;
    std::vector<Node*> mNodes;

    
};