#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define LEN 100005

using namespace std;

//問題に出てくるプロセスを表す構造体
typedef struct pp{
    char name[100];
    int t;
}P;

/*
通常の構造体宣言は以下
struct pp {
    char name[100];
    int t;
};
このときは次のように宣言する
struct pp Q[LEN];
*//*
ここで
typedef struct pp{
    char name[100];
    int t;
}P;
のようにtypedefを使い、最後にPのように別名を設定することで
構造体の宣言を
P Q[LEN]
のように簡単にできる
*/

P Q[LEN];
int head,tail,n;

void initialize(){
    head=0;
    tail=0;
}

bool isFull(){
    return head==(tail+1)%MAX;
}

void enqueue(P x){
    Q[tail]=x;
    tail = (tail+1)%LEN
}