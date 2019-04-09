#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define LEN 100005

// using namespace std;

//問題に出てくるプロセスを表す構造体
typedef struct pp
{
    char name[100];
    int t;
} P;

/*
通常の構造体宣言は以下
struct pp {
    char name[100];
    int t;
};
このときは次のように宣言する
struct pp Q[LEN];
*/
/*
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
int head, tail, n;

void initialize()
{
    head = 0;
    tail = 0;
}

bool isFull()
{
    return head == (tail + 1) % LEN;
}

void enqueue(P x)
{
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue()
{
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

//min関数実装
/*
a<b ? a:b;  ?は二項演算子という
a<b == Trueならa,Falseならbを返す
なお、if文とちがって値しか返せなかったような気がする
int min(int a,int b){return a<b ? a:b;}
minをわざわざ定義する必要もないと思うが、intだけなのももったいないので
defineで」書こうと思ったらコンパイル時にごたごたするのでdefineはやめろという記事があった
参考：https://blog.myon.info/entry/2015/12/18/avoid-defining-macros/
そこで関数templateというものがあったので使ってみる
参考：https://qiita.com/hal1437/items/b6deb22a88c76eeaf90c
templateはおまじないを唱えることで同じ処理ならオーバーロードが要らなくなるものらしい
*/
//なお、namespace stdをusingしていると案の定minが衝突するみたいなのでusingをはずしてある　
template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}
//こうしてtemplateの呪文を置くことで、Tは任意の型を表す
//また次のようにすることで特定の型の処理のみを変えるテンプレートの特殊化が可能(らしいけど下記のものはエラーがでる)
// template <>
// void min(char a, char b)
// {
//     return ;
// }

int main()
{
    //総経過時間 elaps
    //1回ずつの処理時間 c
    int elaps = 0, c;
    int i, q;
    P u;
    //プロセス数n
    //最大処理量q
    scanf("%d %d", &n, &q);

    //すべてのプロセスをキューに順番に追加する
    for (i = 1; i <= n; i++)
    {
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }
    head = 1;
    tail = n + 1;

    while (head != tail)
    {
        u = dequeue();   //先頭のプロセスを持ってくる
        c = min(q, u.t); //処理時間決定,u.tがqより大きければqだけ処理
        u.t -= c;        //処理時間を減算
        elaps += c;      //経過時間加算
        if (u.t > 0)
            enqueue(u);
        else
        {
            printf("%s %d\n", u.name, elaps);
        }
    }

    return 0;
}
