#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

//スタックを実装する配列S
//スタックに必要な、最後尾のindexを示す変数top
int MAX=1000;
int top,S[1000];



bool isEmpty()
{
    return top == 0;
}

bool isFull()
{
    return top > (MAX-1);
}

//pushは配列最後尾に要素を追加する
//このときtopのindexも1つ増やす
void push(int x)
{
    if(isFull())
    {
        cout<<"overflow!!"<<endl;
        return;
    }
    //++topという記法は
    //topに+1し、そのtopのindexを用いる操作を行うことができる
    S[++top] = x;
    //したがって以下に同等
    //top++;
    //S[top] = x;
}

//popはtopが表すindexを1つ後退させ
//後退前の要素を返す
int pop()
{
    if(isEmpty())
    {
        cout<<"Empty!!"<<endl;
        return -1;
    }
    top--;
    return S[top+1];
}




int main()
{
    int a,b;
    top = 0;
    //入力文字列ｓ(小文字)
    char s[100];

    //EOFはファイル終端を表す
    //したがって終端までwhile文が回り続ける
    // scanfの戻り値は読み込めた要素数,第二引数以降に要素数を指定できる
    // デフォは１
    //読み込めなかったときは-1が返る
    //一方でEOFは数字としては-1として認識される(Falseと似てるね。確認済み)ようなのでそこの等値比較を行っている
    while( scanf("%s",s)  != EOF )
    {
        if( s[0]=='+')
        {
            b=pop();
            a=pop();
            push(a+b);
        }else if(s[0]=='-')
        {
            b=pop();
            a=pop();
            push(a-b);
        }else if(s[0]=='*')
        {
            b=pop();
            a=pop();
            push(a*b);
        }else
        {
            //atoi(const char *str) 文字列→int  変換
            //変換不能値は0
            push(atoi(s));
        }
    }

    printf("%d\n",pop());

    return 0;

}

