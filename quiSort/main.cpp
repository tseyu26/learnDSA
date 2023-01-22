//
// Created by tseyusp6 on 1/20/23.
//
#include <iostream>

template <typename T>
void quiSort(T (&array)[], int start, int end){
    if (start >= end){
        return;
    }
    int left = start;
    int right = end;
    T index = array[left];
    while(left < right){
        while (index <= array[right] && left < right){
            right--;
        }
        array[left] = array[right];
        while (index >= array[left] && left < right){
            left++;
        }
        array[right] = array[left];
    }
    array[left] = index;
    quiSort(array,left + 1,end);
    quiSort(array,start, left-1);
}

int main(){
    std::cout << "Before sorting: \n";
    int array[]={2,41,21,32,123,54,23,65,21,93};
    int length = sizeof(array)/ sizeof(array[0]);
    for (int i{0}; i < length; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\nAfter sorting: \n";
    quiSort<int>(array, 0, length-1);
    for (int i{0}; i < length; i++){
        std::cout << array[i] << " ";
    }

    std::cout << "\nBefore sorting: \n";
    double arrayDouble[]={2.2,312,2.34,6.3,43.2,8.2,34.6,9.3,21.4,0};
    int lengthDouble = sizeof(arrayDouble)/ sizeof(arrayDouble[0]);
    for (int i{0}; i < length; i++){
        std::cout << arrayDouble[i] << " ";
    }
    std::cout << "\nAfter sorting: \n";
    quiSort<double>(arrayDouble, 0, length-1);
    for (int i{0}; i < lengthDouble; i++){
        std::cout << arrayDouble[i] << " ";
    }

    return 0;
}