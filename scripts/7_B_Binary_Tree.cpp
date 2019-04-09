#include <cstdio>
#define MAX 10000
#define NIL -1

struct Node{int parent, left, right;};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d)
{
    if (u == NIL)
        return;
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHeight(int u)
{
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL)
        h1 = setHeight(T[u].left) + 1;
    if (T[u].right != NIL)
        h2 = setHeight(T[u].right) + 1;

    //左右の子で深いほうの深さを選択
    return H[u] = (h1 > h2 ? h1 : h2);
}


//節点uの兄弟を返す
int getSibling(int u)
{
    //親がないとき(rootのとき)
    if(T[u].parent==NIL)return NIL;
    //親の左子がuではない かつ 親の左子がNILでない
    //-->uが子　かつ　右子である　
    if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL)
        return T[T[u].parent].left;
    //uが子　かつ　左子である　
    if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL)
        return T[T[u].parent].right;

    return NIL;
}

void print(int u)
{
    printf("node %d: ",u);
    printf("parent = %d, ",T[u].parent);
    printf("sibling = %d, ",getSibling(u));
    //degree : 各頂点 (vertex) の次数（各頂点に出入りする辺の数）
    int deg=0;
    //子がいるときdeg++
    if(T[u].left != NIL)deg++;
    if(T[u].right!=NIL)deg++;

    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);

    if(T[u].parent == NIL)
    {
        printf("root\n");
    }
    else if(T[u].left==NIL && T[u].right==NIL)
    {
        printf("leaf\n");
    }
    else
    {
        printf("internal node\n");
    }
}

int main()
{
    //v: node ID
    //l: left child node ID
    //r:right child node ID
    int v,l,r,root=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)T[i].parent=NIL;

    //入力からnodeのchild&parentを設定
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&v,&l,&r);
        T[v].left=l;
        T[v].right=r;
        //子が存在するとき、vの子であることを設定
        if(l!=NIL)T[l].parent=v;
        if(r!=NIL)T[r].parent=v;
    }

    //全nodeからroot nodeを探索
    for(int i=0;i<n;i++)
    {
        if(T[i].parent==NIL) root=i;
    }

    setDepth(root,0);
    setHeight(root);

    for(int i=0;i<n;i++) print(i);

    return 0;
}




