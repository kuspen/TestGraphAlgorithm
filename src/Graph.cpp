#include "Graph.h"

Graph::Graph(int xSize, int ySize, std::vector<std::vector<int>> graphInfo) : mXSize(xSize), mYSize(ySize){

    for(int y = 0; y < ySize; y++) {
        for(int x = 0; x < xSize; x++) {
            Node *node = new Node(x, y);
            this->SetNode(node);
        }
    }

    for(int y = 0; y < ySize; y++) {
        for(int x = 0; x < xSize; x++) {

            if(y != 0) {
                // Not Upper left
                if(x != 0) {
                }
                // Not Upper right
                else if(x != xSize - 1) {

                }
            }
            else if(y != ySize - 1) {
                // Not Buttom left
                if(x != 0) {

                }
                // Not Button right
                else if(x != xSize - 1) {

                }
            }
        }
    }

}

Graph::~Graph() {

}