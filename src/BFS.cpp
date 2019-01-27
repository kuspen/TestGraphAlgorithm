#include <iostream>
#include <queue>
#include <unistd.h>

#include "BFS.h"
#include "Node.h"


BFS::BFS(Graph graph) : mGraph(graph) {}
BFS::~BFS() {}

void BFS::solve() {

    std::queue<Node*> nodes;
    nodes.push(mGraph.GetStartNode());

    while(1) {

        if(nodes.empty()) {
            std::cout << "Not Found\n";
            return;            
        }

        Node *node = nodes.front();
        nodes.pop();
        node->SetKind(Node::VISITED);

        std::vector<Node*> adjacentNodes;
        node->GetAdjacentNode(adjacentNodes);

        mGraph.ShowGraph();
        std::cout << "\n";
        sleep(1);

        for(auto itr = adjacentNodes.begin(); itr != adjacentNodes.end(); itr++) {
            if((*itr)->GetKind() == Node::END) {
                std::cout << "Found\n";
                return;
            }
            else if((*itr)->GetKind() == Node::NORMAL) {
                nodes.push(*itr);
                (*itr)->SetKind(Node::CHECKED);
            }
        }
    }
}