//
// Created by tseyu on 1/7/23.
//
#include <iostream>

const int capacity = 10;
class Stack{
    int top{-1};
    int data[capacity]{};
public:
    bool push(int index, int data);
    bool pop();
    void printStackElem();
};

bool Stack::push(int index, int elem) {
    if (top == capacity || index > capacity || index < -1 || index!=top+2){
        std::cout << "\nError!" << elem <<" is not inserted!";
        return false;
    }
    data[++top] = elem;
    std::cout << elem << " Inserted!Now top is " << top <<" and index is "<< index<< std::endl;

    return true;
}

bool Stack::pop() {
    std::cout <<data[top]<< " is popped!\n";
    data[top] =0;
    top--;
    std::cout <<"Now top is " << top<<"\n";
    return true;
}

void Stack::printStackElem() {
    int temp{top};

    while (top!=-1){
        std::cout << data[top] << " ";
        top--;
    }
    while (top!= temp){
        top ++;
    }

}

int main(){
    Stack stack;
    stack.push(1, 3);
    stack.push(2, 43);
    stack.push(3, 5);
    stack.push(4, 45);
    stack.push(5, 563);
    stack.push(6, 2);
    stack.push(7, 4);
    stack.push(8, 78);
    stack.push(9, 32);
    stack.push(10, 13);
    stack.pop();
    stack.push(10, 14);
    std::cout << "\n";
    stack.printStackElem();

    return 0;
}