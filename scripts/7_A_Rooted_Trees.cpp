#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1


struct Node{int p,l,r;};

Node T[MAX];
int n,D[MAX];

void print(int u)
{
    int i,c;
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].p<<", ";
    cout<<"depth = "<<D[u]<<", ";

    if(T[u].p==NIL)cout<<"root, ";
    else if(T[u].l==NIL)cout<<"leaf, ";
    else cout<<"internal node, ";

    cout<<"[";

    for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r)
    {
        if(i)cout<<", ";
        cout<<c;
    }

    cout<<"]"<<endl;
}

//再帰的に深さを求める
void rec(int u,int p)
{
    D[u]=p;
    if(T[u].r!=NIL)rec(T[u].r,p);//右兄弟にも同じ深さp
    if(T[u].l!=NIL)rec(T[u].l,p+1);//最左の子には深さp+1
}


int main()
{
    int i,j,d,v,c,l,r;
    //全体node数n
    cin>>n;
    for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=NIL;

    for(i=0;i<n;i++)
    {
        //vは入力1行に１つのnodeID
        //dは入力1行に１つの次数(子のnode数)
        cin>>v>>d;
        //vの子のindexに相当j=0-->(d-1)
        for(j = 0; j < d ; j++)
        {
            //毎回node vの子c1,c2,...が入ってくる
            cin>>c;
            //(子index)j==0 <--> 子 第1nodeのとき
            if(j==0)T[v].l=c;
            //(深さ)j>=1 <-->　2つ目以降の子node
            //c1以降は右兄弟を次々代入
            else T[l].r=c;
            //うえのelseで使うlへの代入
            //毎回行われ、lはNULL->c1->c2->...と変遷
            l=c;
            //子nodeたちの親は全てv
            T[c].p=v;
        }
    }
    for(i = 0; i < n; i++)
    {
        //全nodeからroot nodeを探索
        if(T[i].p==NIL)r=i;
    }

    //root nodeは見つけたので
    //root nodeの深さ0から全nodeに深さを求める
    rec(r,0);

    for( i = 0; i < n; i++)print(i);

    return 0;
}