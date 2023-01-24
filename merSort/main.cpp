//
// Created by tseyusp6 on 1/24/23.
//
#include <iostream>

template<typename T1>
void conArray(T1 arr[], int low, int mid, int high){
    T1* tempArray = new T1[high-low+1];
    int i{low}, j{mid+1}, k{0};

    while(i <= mid && j<= high){
        if (arr[i] < arr[j]){
            tempArray[k] = arr[i];
            i++;
        }else{
            tempArray[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid){
        tempArray[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high){
        tempArray[k] = arr[j];
        k++;
        j++;
    }

    i = low;
    for (int tempK{0};((tempK < k)&&(i <= high));tempK++){
        arr[i] = tempArray[tempK];
        i++;
    }

    delete[] tempArray;
}

template<typename T>
void divArray(T arr[], int low, int high){
    if (low < high){
        int mid {(high + low)/2};
        divArray(arr, low, mid);
        divArray(arr, mid+1, high);
        conArray(arr, low, mid, high);
    }
}

int main(){
    std::cout << "Before Sorting:\n";
    int intArray[] ={4,2,3,1,6,7,5,8,10,9};
    for (int i{0}; i < 10;i++){
        std::cout << intArray[i] << " ";
    }
    std::cout << "\nAfter Sorting:\n";
    divArray<int>(intArray, 0, 9);
    for (int i{0}; i < 10;i++){
        std::cout << intArray[i] << " ";
    }
    std::cout << "\nBefore Sorting:\n";
    double doubleArray[] ={4.3,2.6,3.7,1.8,6.0,7.2,5.4,8.5,10.7,9.43};
    for (int i{0}; i < 10;i++){
        std::cout << doubleArray[i] << " ";
    }
    std::cout << "\nAfter Sorting:\n";
    divArray<double>(doubleArray, 0, 9);
    for (int i{0}; i < 10;i++){
        std::cout << doubleArray[i] << " ";
    }
    return 0;
}