#include <iostream>
#include <utility>

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

            // Not Upper left
            if(x != 0) {
                if(graphInfo[y][x-1] == NODE_NORMAL) {
                    GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x-1, y));
                }
            }
            // Not Upper right
            if(x != xSize - 1) {
                if(graphInfo[y][x+1] == NODE_NORMAL) {
                    GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x+1, y));
                }
            }
            // Not Buttom left
            if(y != 0) {
                if(graphInfo[y-1][x] == NODE_NORMAL) {
                    GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x, y-1));
                }
            }
            // Not Button right
            if(y != xSize - 1) {
                if(graphInfo[y+1][x] == NODE_NORMAL) {
                    GetNodeByIndex(x, y)->SetAdjacentNode(GetNodeByIndex(x, y+1));
                }
            }
            
        }
    }
}

Graph::~Graph() {

}

Graph::Graph(const Graph &graph) : mXSize(graph.mXSize), mYSize(graph.mYSize) {

    std::vector<std::vector<std::pair<int, int>>> adjacemtNodeInfo;
    
    for(auto itr=graph.mNodes.begin(); itr != graph.mNodes.end(); itr++) {
        Node *node = new Node((*itr)->GetXIndex(), (*itr)->GetYIndex());
        node->SetKind((*itr)->GetKind());
        SetNode(node); 

        std::vector<Node*> tempAdjacentNodes;
        std::vector<std::pair<int, int>> tempAdjacentPair;
        (*itr)->GetAdjacentNode(tempAdjacentNodes);
        for(auto temp_itr = tempAdjacentNodes.begin(); temp_itr != tempAdjacentNodes.end(); temp_itr++) {
            std::pair<int, int> pair = std::make_pair((*temp_itr)->GetXIndex(), (*temp_itr)->GetYIndex());
            tempAdjacentPair.push_back(pair);
        }
        adjacemtNodeInfo.push_back(tempAdjacentPair);
    }

    auto adjaInfoItr = adjacemtNodeInfo.begin();
    for(auto itr=mNodes.begin(); itr!=mNodes.end(); itr++) {
        for(auto pairItr = (*adjaInfoItr).begin(); pairItr != (*adjaInfoItr).end(); pairItr++) {
            (*itr)->SetAdjacentNode(GetNodeByIndex((*pairItr).first, (*pairItr).second));
        }
        adjaInfoItr++;
    }

    SetStartNode(graph.GetStartNode()->GetXIndex(), graph.GetStartNode()->GetYIndex());
    SetEndNode(graph.GetEndNode()->GetXIndex(), graph.GetEndNode()->GetYIndex());

}

void Graph::SetStartNode(int xIndex, int yIndex) {
    mStartNode = GetNodeByIndex(xIndex, yIndex);
    mStartNode->SetKind(Node::START);
}

void Graph::SetEndNode(int xIndex, int yIndex) {
    mEndNode = GetNodeByIndex(xIndex, yIndex);
    mEndNode->SetKind(Node::END);
}

Node* Graph::GetStartNode() const {
    return mStartNode;
}

Node* Graph::GetEndNode() const {
    return mEndNode;
}

void Graph::ShowGraph() {
    for(int y = 0; y < mYSize; y++) {
        for(int x = 0; x < mXSize; x++) {
            Node::EKind kind = GetNodeByIndex(x, y)->GetKind();
            if(kind == Node::NORMAL || kind == Node::CHECKED) std::cout<<".";
            else if(kind == Node::VISITED)                    std::cout<<"*";
            else if(kind == Node::WALL)                       std::cout<<"#";
            else if(kind == Node::START)                      std::cout<<"s";
            else if(kind == Node::END)                        std::cout<<"e";
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
