//
// Created by tseyusp6 on 1/19/23.
//

#include <iostream>

template <typename T>
void bubSort(T arr[], int arrLen){
    for (int j{arrLen};j>0;j--){
        for (int i{0}; i < arrLen - 1;i++){
            if (arr[i+1] < arr[i]){
                T temp {arr[i]};
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    for (int i{0};i < arrLen;i++){
        std::cout << arr[i] << " ";
    }
}

int main(){
    std::cout << "before sorting:\n";
    int arr1[]={1,23,52,124,32,12,43,65,38,19};
    int arrayLen1 = sizeof(arr1)/sizeof(arr1[0]);
    for (int i{0};i < sizeof(arr1)/ sizeof(arr1[0]);i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << "\nafter sorting:\n";
    bubSort<int>(arr1,arrayLen1);

    std::cout << "\nbefore sorting:\n";
    double arr2[]={4.9,238,384.9,213.2,354.3,8.473,90.264};
    int arrayLen2 = sizeof(arr2)/ sizeof(arr2[0]);
    for (int i{0};i<arrayLen2;i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << "\nafter sorting:\n";
    bubSort<double>(arr2,arrayLen2);
    return 0;
}
