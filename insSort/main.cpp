//
// Created by tseyusp6 on 1/20/23.
//
#include <iostream>

template<typename T>
void insSort(T arr[], int arrayLen){
    for (int i{0};i < arrayLen-1;i++){
        if (arr[i] <= arr[i+1]){
            continue;
        }else{
            T tempOut = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tempOut;
            for (int j{i};j > 0;j--){
                if (arr[j] > arr[j-1]){
                    break;
                }else{
                    T tempIn = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tempIn;
                }
            }
        }
    }
    for (int i{0};i<arrayLen;i++){
        std::cout << arr[i] << " ";
    }
}



int main(){
    std::cout << "Before sorting: \n";
    int arrInt[]={2,34,29,34,53,24,2, 48,35,25,58};
    int lenInt = sizeof(arrInt)/sizeof(arrInt[0]);
    for (int i{0};i<lenInt;i++){
        std::cout << arrInt[i] << " ";
    }
    std::cout <<"\nAfter sorting\n";
    insSort<int>(arrInt,lenInt);
    std::cout <<"\n";

    std::cout << "Before sorting: \n";
    double arrDouble[]={2.3,478,3.0,37.3,48.5,37.2,12.2,0.2,34.1,21.8};
    int lenDouble = sizeof(arrDouble)/sizeof(arrDouble[0]);
    for (int i{0};i < lenDouble;i++){
        std::cout << arrDouble[i] << " ";
    }
    std::cout <<"\nAfter sorting\n";
    insSort<double>(arrDouble,lenDouble);
    std::cout <<"\n";
    return 0;
}