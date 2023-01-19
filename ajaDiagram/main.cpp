//
// Created by tseyusp6 on 1/18/23.
//
// met up with some problems
#include <iostream>

const int maxVertex {5};

class ajaDiag{
    int vertexCount;
    int edgeCount;
    struct Node{
        int data;
        struct Node* next;
    };
    struct headNode{
        int data;
        struct Node* next;
    };
    headNode headNode[maxVertex];
public:
    ajaDiag();
    void addVertex(int element);
    void addEdge(int a, int b);
    void showDiagram();
};

ajaDiag::ajaDiag() {
    // init the diagram
    vertexCount = 0;
    edgeCount = 0;
}

void ajaDiag::addVertex(int element) {
    if (this->vertexCount >= maxVertex){
        return;
    }
    this->headNode[this->vertexCount].data = element;
    this->headNode[this->vertexCount].next = nullptr;
    this->vertexCount++;
}

void ajaDiag::addEdge(int a, int b) {
    Node* tempNode = headNode[a].next;
    Node* newNode = new Node;
    newNode->data = b;
    newNode->next = nullptr;
    if (!tempNode){
        headNode[a].next = newNode;
        std::cout << "add the first num " << headNode[a].next->data << "\n";
    }else{
        do{
            if (tempNode->next){
                tempNode = tempNode->next;
            }else{
                break;
            }
        }while(true);
        tempNode->next = newNode;
    }
    delete newNode;
}

void ajaDiag::showDiagram() {
    for (int i{0};i < vertexCount;i++){
        std::cout << headNode[i].data << "->";
        /*Node* tmpNode = headNode[i].next;
        while (tmpNode){
            std::cout << tmpNode->data << "->";
            tmpNode = tmpNode->next;
        }*/
        std::cout << headNode[i].next->data;
        std::cout << "\n";
    }
}

int main(){
    std::cout << "adjacent graph ... \n";
    ajaDiag aD;
    for (int i{0}; i < 4;i++){
        aD.addVertex(i);
    }
    aD.addEdge(0, 1);
    aD.addEdge(1, 2);
    aD.addEdge(2, 3);
    aD.addEdge(3, 0);
    aD.addEdge(2, 0);
    aD.showDiagram();
    return 0;
}
