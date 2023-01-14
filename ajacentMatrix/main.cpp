//
// Created by tseyu on 1/14/23.
//
#include <iostream>

const int vertexSum {4};

class ajacentMatrix{
private:
    int vertexCount{0};    // initialize the vertex count
    int edgeCount{0};      // initialize the edge count
public:
    int matrix[vertexSum][vertexSum];  // initialize the matrix
    int data[vertexSum];               // initialize the data array
    ajacentMatrix();                   // constructor
    int getVertexCount();              // achieve the vertex count
    void addVertexCount();             // add the vertex count
    void addVertex(int data);                                  // add the vertex
    void addEdge(int vertexA, int vertexB);                    // add the edge
};

ajacentMatrix::ajacentMatrix() {
    vertexCount = 0;
    edgeCount = 0;
    for (int i{0}; i < vertexSum;i++){
        this->data[i] = 0;
    }
    for (int i{0}; i < vertexSum; i++){
        for (int j{0}; j < vertexSum; j++){
            this->matrix[i][j] = 0;
        }
    }
}

int ajacentMatrix::getVertexCount() {
    return vertexCount;
}

void ajacentMatrix::addVertexCount() {
    this->vertexCount++;
}

void ajacentMatrix::addVertex(int dataE) {
    if (getVertexCount() >= vertexSum){
        return;
    }else{
        this->data[getVertexCount()] = dataE;
        addVertexCount();
    }
}

void ajacentMatrix::addEdge(int a, int b) {
    if (this->matrix[a][b]==0){
        this->matrix[a][b] = 1;
    }
}

int main(){
    ajacentMatrix aM;
    std::cout << "Initializing the matrix ...\n";
    for (int i{0};i<vertexSum;i++){
        for (int j{0};j<vertexSum;j++){
            std::cout << aM.matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Initializing the data array ... \n";
    aM.addVertex(0);
    aM.addVertex(1);
    aM.addVertex(2);
    aM.addVertex(3);
    for (int i{0};i<vertexSum;i++){
        std::cout << aM.data[i] << " ";
    }
    std::cout << "\n";

    aM.addEdge(0,1);
    aM.addEdge(1,2);
    aM.addEdge(2,3);
    aM.addEdge(3,0);
    aM.addEdge(2,0);

    std::cout << "Now the Matrix ...\n";
    for (int i{0};i<vertexSum;i++){
        for (int j{0};j<vertexSum;j++){
            std::cout << aM.matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
