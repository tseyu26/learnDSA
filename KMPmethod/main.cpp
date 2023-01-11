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
// getNext on textbook, hard to understand
void getNext(const char* p, int * next){
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

//
void prefixTable(const char* p, int *pmt, int n){ // p means the module string, n means the length of pmt
    pmt[0] = 0;
    int len = 0;     // in string
    int i = 1;       // in pmt
    while ( i < n){
        if ( p[i] == p[len]){
            len++;
            pmt[i] = len;
            i++;
        }else{
            if (len >  0){
                len = pmt[len-1];
            }else{
                pmt[i] = len;
                i++;
            }
        }
    }
}

void movePmt (int *pmt, int n){
    int i;
    for (i=n-1;i>0;i--){
        pmt[i] = pmt[i-1];
    }
    pmt[0] =-1;
}

void kmpSearch(const char *text, const char *pattern){
    int n = strlen(pattern);
    int *pmt = new int[n];
    prefixTable(pattern,pmt,n);

    movePmt(pmt, n);

    // text[i]     len:m
    // pattern[j]  len:n
    int i{0};
    int j{0};
    int m = strlen(text);

    while (i < m){
        if (j == n-1 && pattern[j]==text[i]){
            std::cout << "Found @ "<< i-j << "\n";
            j = pmt[j];
        }
        if (text[i] == pattern[j]){
            i++; j++;
        }else{
            j = pmt[j];
            if (j == -1){
                i++;
                j++;
            }
        }
    }
    delete [] pmt;
}

int main(){
    char pattern[] = "ababcabaa";
    char text[] = "abababcabaabababab";
    //bruteForce(text,pattern);

    kmpSearch( text, pattern);

    return 0;
}