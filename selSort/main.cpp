//
// Created by tseyusp6 on 1/20/23.
//
#include <iostream>

template <typename T>
void selSort(T array[], int arrayLen){
    for (int i{0}; i < arrayLen-1; i++){
        int flag = i;
        T temp;
        for (int j{i+1}; j < arrayLen ; j++){
            if (array[flag] > array[j]){
                flag = j;
            }
        }
        temp = array[i];
        array[i] = array[flag];
        array[flag] = temp;
    }
    for (int i{0}; i < arrayLen; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    std::cout << "Before sorting:\n";
    int intArray[]={23,532,134,64,23,34,65,3422,12,432};
    int intLen = sizeof(intArray)/ sizeof(intArray[0]);
    for (int i{0}; i < intLen;i++){
        std::cout << intArray[i] << " ";
    }
    std::cout << "\nAfter sorting:\n";
    selSort<int>(intArray, intLen);

    std::cout << "Before sorting:\n";
    double doubleArray[]={213.421,243.6,12.4,8.9,0.1,34.2,345.5,54.2,76.2,1};
    int doubleLen = sizeof(doubleArray)/ sizeof(doubleArray[0]);
    for (int i{0}; i < doubleLen;i++){
        std::cout << doubleArray[i] << " ";
    }
    std::cout << "\nAfter sorting:\n";
    selSort<double>(doubleArray, doubleLen);

    return 0;
}


