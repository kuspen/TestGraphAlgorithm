#pragma once

#include <vector>

#include "Node.h"

class Graph {
public:
    Graph(int xSize, int ySize, std::vector<std::vector<int> > graphInfo);
    ~Graph();

    void SetNode(Node *node) { mNodes.push_back(node); }
    void SetStartNode(int xIndex, int yIndex);
    void SetEndNode(int xIndex, int yIndex);

    void ShowGraph();

private:
    int mXSize;
    int mYSize;
    std::vector<Node*> mNodes;
    Node* mStartNode;
    Node* mEndNode;

    Node* GetNodeByIndex(int xIndex, int yIndex);
};