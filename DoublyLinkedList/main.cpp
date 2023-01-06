//
// Created by tseyu on 1/6/23.
//
#include <iostream>

class List{
private:
    class Node{
    public:
        int data;
        Node *prior;
        Node *next;
    };
    Node *head;
    int length;
public:
    List();
    void print();
    void create(int n);
    int getLength();
    void insertByIndex(int index, int data);
    void deleteByIndex(int index);
};

List::List() {
    head = new Node;
    head->data = 0;
    head->next = nullptr;
    head->prior = nullptr;
}

void List::print() {
    Node *cur = head->next;
    if (!length){
        std::cout << "empty!" << std::endl;
        return;
    }
    while (cur){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void List::create(int n) {
    Node *pre = head;
    length = n;
    int i {1};
    while (i <= n){
        std::cout << "Input the "<< i << " number: ";
        Node *cur = new Node;
        std::cin >> cur->data;
        ++i;
        pre->next = cur;
        cur->prior = pre;
        pre = cur;
        cur->next = nullptr;
        //delete(cur);
    }
}

int List::getLength() {
    std::cout << "the element num of the list: " << length << std::endl;
    return length;
}

void List::insertByIndex(int index, int data) {
    if (index<0||index>=length){
        std::cout << "Error"<< std::endl;
    }else{
        Node *cur =head;
        int pos = 0;
        while (pos != index){
            cur = cur->next;
            ++pos;
        }
        ++length;
        Node *temp = new Node;
        temp->data = data;
        temp->next = cur->next;
        temp->prior = cur;
        cur->next->prior = temp;
        cur->next = temp;
        std::cout << data << " inserted!" << std::endl;
    }
}

void List::deleteByIndex(int index) {
    if (index <0 || index>length){
        std::cout << "Error!" << std::endl;
    }
    if (index == length){
        Node *cur = head;
        int pos {0};
        while (pos!=index){
            cur = cur->next;
            ++pos;
        }
        cur = cur->prior;
        cur->next = nullptr;
        length--;
    }else{
        Node *cur = head;
        int pos = 0;
        while (pos !=index){
            cur = cur->next;
            ++pos;
        }
        cur = cur->prior;
        Node *temp = cur->next;
        temp->next->prior = temp->prior;
        temp->prior->next = temp->next;
        delete(temp);
        //delete(cur);
        --length;
        std::cout << "Deleted!" << std::endl;
    }
}

int main(){
    List list;
    int n;
    std::cout << "Input node num: ";
    std::cin >> n;
    list.create(n);
    list.print();
    list.getLength();
    int index{};
    int data{};
    std::cout << "Input index and data: ";
    std::cin >> index >> data;
    list.insertByIndex(index,data);
    list.print();
    list.getLength();
    int deleteIndex{};
    std::cout << "Input the index to be deleted: ";
    std::cin >> deleteIndex;
    list.deleteByIndex(deleteIndex);
    list.print();
    list.getLength();
    return 0;
}