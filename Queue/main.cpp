//
// Created by tseyu on 1/8/23.
//
#include <iostream>

const int length = 10;
class Queue{
    int front{0};
    int rear{0};
    int data[length]{};
public:
    Queue();
    void push(int elem);
    void pop();
    int getLength();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    void printQueue();
};

Queue::Queue() {
    std::cout << "Queue initialized.\n";
    for (int i{0};i<length;i++){
        data[i] = 0;
    }
}

bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }else{
        return false;
    }
}

bool Queue::isFull() {
    if ((rear+1)%length==front){
        return true;
    }else{
        return false;
    }
}

void Queue::printQueue() {
    for (int i{0};i<length;i++){
        std::cout << data[i]<<  " ";
    }
    std::cout <<"\n";
}

int Queue::getLength() {
    return (rear+length-front)%length;
}

int Queue::getFront() {
    return front;
}

int Queue::getRear() {
    return rear;
}

void Queue::push(int elem) {
    if (isFull()){
        std::cout << "the Queue is full!\n";
    }else{
        //std::cout<<"rear:" << rear <<" "<<"getLength(): "<< getLength();
        data[rear] = elem;
        //std::cout << elem <<" is inserted.\n";
        rear= (rear+1)%length; // after inserting, set the rear value.
        //std::cout<<" rear:" << rear <<"\n";
    }
}

void Queue::pop(){
    if (isEmpty()){
        std::cout << "Empty!\n";
    }else{
        data[front]=0;
        //std::cout << " \npopped.\n";
        front = (front + 1)%length;
        //std::cout<<" front:" << front <<"\n";
    }
}

int main(){
    Queue queue;
    for (int k{0};k<10;++k){

        for (int i{0};i < length-1;++i){
            queue.push(1);
            //queue.printQueue();
        }
        queue.printQueue();
        for (int i{0};i<length-1;++i){
            queue.pop();
            //queue.printQueue();
        }

    }

    return 0;
}