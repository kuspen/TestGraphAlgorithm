#pragma once

#include <vector>

class Node {
public:
    Node();
    Node(int xIndex, int yIndex);
    ~Node();

    enum EKind {NORMAL, VISITED, WALL, START, END};

    void SetXIndex(int xIndex) { mXIndex = xIndex; }
    int GetXIndex() { return mXIndex; }
    void SetYIndex(int yIndex) { mYIndex = yIndex; }
    int GetYIndex() { return mYIndex; }

    void SetKind(EKind kind) { mKind = kind; }
    EKind GetKind() { return mKind; }

    void SetAdjacentNode(Node *node) { mAdjacentNodes.push_back(node); }
    void GetAdjacentNode(std::vector<Node*>& AdjacentNodes) { AdjacentNodes = mAdjacentNodes; }


private:
    int mXIndex;
    int mYIndex;

    EKind mKind;

    std::vector<Node*> mAdjacentNodes;

};