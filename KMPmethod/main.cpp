//
// Created by tseyu on 1/8/23.
//

#include <iostream>
#include <cstring>

// bruteForce method
void bruteForce(char *S, char *P){
    size_t lenS =strlen(S);
    size_t lenP = strlen(P);
    // set the loop length lenS-lenP
    for (int i{0};i < lenS-lenP;i++){
        bool flag = true;
        // start to match
        for (int j{0}; P[j]!='\0';j++){
            if (S[i+j]!=P[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            std::cout << "pos: "<< i << std::endl;
        }
    }
}

// KMP method

void get_next(const char* p, int * next){
    int k = -1, j=0;
    next[0] = -1;
    while ( j < strlen(p)-1){
        if (k==-1 || p[j]==p[k]){
            ++k; ++j;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}

int main(){
    char S[] = "aaaaaaabc";
    char P[] = "abaabcaba";
    bruteForce(S,P);
    int *pmt = new int[strlen(P)];
    get_next(P,pmt);
    for (int i{0};i<strlen(P);i++){
        std::cout << pmt[i] << " ";
    }
    return 0;
}