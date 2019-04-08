#include <cstdio>
#include<stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int bubblesort(int A[],int N){
    int sw=0;
    bool flag=1;
    while(flag){
        flag=0;
        for(int j=N-1 ; j>=1 ; j--){
            if(A[j] < A[j-1]) {
                swap(A[j],A[j-1]);
                flag=1;
                sw++;
            }
        }

    }
    return sw;
}

int main(void){
    int A[100],N,sw;
    cin >> N;

    for(int i=0 ; i<N ; i++) cin >> A[i];

    sw=bubblesort(A,N);

    for(int i=0 ; i<N ; i++){
        if(i) cout << " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;

    return 0;
}