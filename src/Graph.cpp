#include "iostream"

#include "Graph.h"
#include "define.h"


Graph::Graph(int xSize, int ySize, std::vector<std::vector<int> > graphInfo) : mXSize(xSize), mYSize(ySize){

    for(int y = 0; y < ySize; y++) {
        for(int x = 0; x < xSize; x++) {
            Node *node = new Node(x, y);
            if(graphInfo[y][x] == NODE_NORMAL)    node->SetKind(Node::NORMAL);
            else if(graphInfo[y][x] == NODE_WALL) node->SetKind(Node::WALL);
            SetNode(node);
        }
    }

    for(int y = 0; y < ySize; y++) {
        for(int x = 0; x < xSize; x++) {

            if(y != 0) {
                // Not Upper left
                if(x != 0) {
                    if(graphInfo[y-1][x-1] == NODE_NORMAL) {
                        GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x-1, y-1));
                    }
                }
                // Not Upper right
                else if(x != xSize - 1) {
                    if(graphInfo[y-1][x+1] == NODE_NORMAL) {
                        GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x+1, y-1));
                    }
                }
            }
            else if(y != ySize - 1) {
                // Not Buttom left
                if(x != 0) {
                    if(graphInfo[y+1][x-1] == NODE_NORMAL) {
                        GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x-1, y+1));
                    }
                }
                // Not Button right
                else if(x != xSize - 1) {
                    if(graphInfo[y+1][x+1] == NODE_NORMAL) {
                        GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x+1, y+1));
                    }
                }
            }
        }
    }
}

Graph::~Graph() {

}

void Graph::SetStartNode(int xIndex, int yIndex) {
    mStartNode = GetNodeByIndex(xIndex, yIndex);
    mStartNode->SetKind(Node::START);
}

void Graph::SetEndNode(int xIndex, int yIndex) {
    mEndNode = GetNodeByIndex(xIndex, yIndex);
    mEndNode->SetKind(Node::START);
}

void Graph::ShowGraph() {
    for(int y = 0; y < mYSize; y++) {
        for(int x = 0; x < mXSize; x++) {
            Node::EKind kind = GetNodeByIndex(x, y)->GetKind();
            if(kind == Node::NORMAL)       std::cout<<".";
            else if(kind == Node::VISITED) std::cout<<"*";
            else if(kind == Node::WALL)    std::cout<<"#";
            else if(kind == Node::START)   std::cout<<"s";
            else if(kind == Node::END)     std::cout<<"e";
        }
        std::cout << "\n";
    }
}

Node* Graph::GetNodeByIndex(int xIndex, int yIndex) {
    for(auto itr = this->mNodes.begin(); itr != this->mNodes.end(); itr++) {
        if((*itr)->GetXIndex() == xIndex && (*itr)->GetYIndex() == yIndex) {
            return *itr;
        }
    }
    return nullptr;
}
