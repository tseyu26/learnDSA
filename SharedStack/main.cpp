//
// Created by tseyu on 1/7/23.
//
#include <iostream>
const int length{10};
class SharedStack{
    int top1{-1};
    int top2{length};
    int data[length]{};

public:
    SharedStack(){
        for (int i{0};i<length;i++){
            data[i] = 0;
        }
        std::cout << "Shared stack initialized! \n";
    }

    void printStack(){
        for (int i{length-1};i >= 0;i--){
            std::cout << data[i] << " ";
        }
        std::cout <<"\n";
    }

    bool push(int elem, int stackNum){
        if (top1 + 1 == top2){
            std::cout << "\nFull! Error!\n"<< elem <<" is not inserted!\n";
            return false;
        }
        if (stackNum == 1){
            top1 ++;
            data[top1] = elem;
            return true;
        }
        if (stackNum == 2){
            top2 --;
            data[top2] = elem;
            return true;
        }
        return false;
    }

    bool pop(int stackNum){
        if (stackNum==1 ){
            if (top1 == -1){
                std::cout << "Stack1 is empty!\n";
                return false;
            }else{
                data[top1] = 0;
                top1--;
                return true;
            }
        }
        if (stackNum==2 ){
            if ( top2 == length){
                std::cout << "Stack2 is empty!\n";
                return false;
            }else {
                data[top2] =0;
                top2++;
                return true;
            }
        }
    }
};

int main(){
    SharedStack ss;
    ss.push(1,1);
    ss.push(2,1);
    ss.push(3,1);
    ss.push(4,1);
    ss.push(5,1);
    ss.push(1,2);
    ss.push(2,2);
    ss.push(3,2);
    ss.push(4,2);
    ss.push(5,2);
    ss.push(4,2);
    ss.printStack();
    ss.pop(2);
    ss.pop(1);
    ss.printStack();
    while (ss.pop(2));
    while (ss.pop(1));
    ss.printStack();
    return 0;
}