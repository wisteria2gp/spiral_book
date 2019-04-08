#include <cstdio>
#include<stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//h配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        cout << A[i];
    }
    printf("\n");
}

//挿入ソート
void insertion_sort(int array[],int N){

    for(int i=1; i<N ;i++){
        
        int key=array[i];
        int j=i-1;

        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }

        array[j+1]=key;
        trace(array,N);
    }    
}


int main(){
    int N;
    int A[100];

    cin >> N;

    for(int i=0 ; i<N ; i++) cin >> A[i];

    trace(A,N);
    insertion_sort(A,N);

    return 0;
}