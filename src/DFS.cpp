#include <iostream>
#include <stack>
#include <unistd.h>

#include "DFS.h"
#include "Node.h"


DFS::DFS(Graph *graph) : mGraph(graph) {}
DFS::~DFS() {}

void DFS::solve() {

    std::stack<Node*> nodes;
    nodes.push(mGraph->GetStartNode());

    while(1) {

        if(nodes.empty()) {
            std::cout << "Not Found\n";
            return;            
        }

        Node *node = nodes.top();
        nodes.pop();
        node->SetKind(Node::VISITED);

        std::vector<Node*> adjacentNodes;
        node->GetAdjacentNode(adjacentNodes);

        mGraph->ShowGraph();
        std::cout << "\n";
        sleep(1);

        for(auto itr = adjacentNodes.begin(); itr != adjacentNodes.end(); itr++) {
            if((*itr)->GetKind() == Node::END) {
                std::cout << "Found\n";
                return;
            }
            else if((*itr)->GetKind() == Node::NORMAL) {
                nodes.push(*itr);
            }
        }
    }
}