//
// Created by tseyu on 1/4/23.
//
#include <iostream>

class Point{
    int data;
    Point *next;
public:
    int getdata();
    void setdata(int data);
    Point *getnext();
    void setnext(Point *next);
};

int Point::getdata() {
    return data;
}

void Point::setdata(int data) {
    this->data = data;
}

Point *Point::getnext() {
    return this->next;
}

void Point::setnext(Point *next) {
    this->next = next;
}

class List{
    Point *head;

public:
    int length;
    List();
    bool add(int data);
    bool del(int posi);
    bool insert(int posi, int data);
    int find(int posi);
};

List::List() {
    head = nullptr;
    length = 0;
}

bool List::add(int data) {
    Point *p = new Point();
    p ->setdata(data);
    if (head == nullptr){
        head = p;
        length ++;
        return true;
    }else{
        Point *q = head;
        for (int i{0};i < length-1;i++){
            q = q->getnext();
        }
        q->setnext(p);
        length++;
        return true;
    }
}

bool List::del(int posi) {
    if (posi < 0 || posi>length)
        return false;
    //del head node
    Point *q =head;
    if (posi == 0){
        head = q->getnext();
        length--;
        delete(q);
        return true;
    }
    //del nail node
    if (posi == length){
        Point *a =q;
        for (int i{0};i<posi-1;i++){
            a = a->getnext();
        }
        delete(a);
        length--;
        return true;
    }else{
        //del neither head nor nail
        for(int i{0};i<posi-1;i++){
            q = q->getnext();
        }
        Point *a = q->getnext();
        q->setnext(q->getnext()->getnext());
        delete a;
        length --;
        return true;
    }
}

bool List::insert(int posi, int data){
    if (posi<0 || posi>length){
        return false;
    }
    Point *p =new Point();
    p->setdata(data);
    Point * q=head;
    // insert head
    if (posi == 0){
        p->setnext(q);
        head = p;
        length++;
        return true;
    }else{
        for (int i=0; i<posi-1;i++){
            q = q->getnext();
        }
        length++;
        p->setnext(q->getnext());
        q->setnext(p);
    }
}

int List::find(int posi) {
    if (posi <0 || posi >length){
        std::cout << "del error";
        return 0;
    }
    Point *p =head;
    for(int i{0};i<posi;i++){
        p = p->getnext();
    }
    return p->getdata();
}

int main(){
    List l= List();
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.add(7);
    for (int i{0};i<l.length;i++){
        std::cout << l.find(i)<<" ";
    }
    std::cout << std::endl;
    l.insert(5,6);
    for (int i{0};i<l.length;i++){
        std::cout << l.find(i)<<" ";
    }
    std::cout << std::endl;
    l.del(l.length);
    for (int i{0};i<l.length;i++){
        std::cout << l.find(i)<<" ";
    }
    std::cout << std::endl;
    return 0;
}