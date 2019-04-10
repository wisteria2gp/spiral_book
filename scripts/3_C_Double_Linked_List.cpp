#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Node
{
    int key;
    //next,prev自体はNode型のポインタ
    Node *next,*prev;
};

//nilはNodeポインタ
Node *nil;


//指定のkeyを持つNodeの探索(ポインタを返す)
Node* listSearch(int key)
{
    //current<--(nil->next)
    //nil->nextは連結リストの先頭を示す
    //->はアロー演算子：ポインタからメンバ７にアクセスできる
    Node *cur = nil->next;
    //- curがnil(番兵)-->先頭からスタートして番兵に到達、なので最初から空だったか終点まで探してスカだった
    //- curのkeyが指定のkeyのとき--->目標に到達
    //終点でも探し物を見つけてもいないとき探索を続ける
    while(cur != nil && cur->key != key)
    {
        //cur を１つすすめる
        cur = cur->next;
    }
    //whileを抜けたら
    return cur;
}


//初期化
void init()
{
    //(Node *)はNodeのポインタ型にキャスト
    //malloc()はc標準ライブラリ指定したサイズのメモリを確保する
    nil=(Node *)malloc(sizeof(Node));
    //nilが自己連結しnext,prevが完結する
    nil->next=nil;
    nil->prev=nil;
}


//連結リストのkeyを頭から表示していく
void printList()
{
    //まずcurに先頭を指定
    Node *cur=nil->next;
    //恐らく、is first
    //先頭の時だけ空白を設けないようにするため
    //ex :key key key key
    int isf =0;

    while(1)
    {
        //curが終端に達したらおわり
        if(cur==nil)break;
        //先頭以降は空白表示
        if(isf++ > 0)printf(" ");
        printf("%d",cur->key);
        cur = cur->next;
    }
    printf("\n");
}

//Nodeを指定して消去
void deleteNode(Node *t)
{
    if(t==nil)return;//tが番兵の場合は処理しない
    //次の２処理はどちらもtスキップ
    //prev->t->next  --->  prev->next
    //prevのnextがtのnextになれば良い
    t->prev->next=t->next;
    //prev->t->next  --->  prev->next
    //nextびprevがtのprevになればよい
    t->next->prev=t->prev;
    //メモリを解放
    free(t);
}

void deleteFirst()
{
    deleteNode(nil->next);
}

void deleteLast()
{
    deleteNode(nil->prev);
}

void deleteKey(int key)
{
    //検索したNodeを削除
    deleteNode(listSearch(key));
}

//連結リストの先頭にkeyをキーに持つ要素を継ぎ足す
void insert(int key)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=key;
    //番兵の直後に要素を追加
    x->next=nil->next;
    /*
           x----->
                 |---->next
    prev<==>nil-->
    */


    nil->next->prev=x;
    /*
            x<=====>
                  ||<====>next
    prev<==>nil--\\
    */


    nil->next=x;
    /*
    prev<==>nil-->x<==>next
    */

    x->prev=nil;
    /*
    prev<==>nil<==>x<==>next
    */

}


int main()
{
    int key,n,i;
    //連結リストのsize
    int size=0;
    //commandの配列、20を超えない
    char com[20];
    //
    int np=0,nd=0;
    //n:command数
    scanf("%d",&n);
    //初期化
    init();
    //
    for( i = 0; i < n; i++)
    {
        //com : commandの文字列部分
        //key : Nodeのkey
        scanf("%s%d",com,&key);
        //command==insertのとき
        //np : insert回数？
        //連結リストのsize+1
        if(com[0]=='i'){insert(key);np++;size++;}
        //１文字目がdだとdeleteFirst,deleteLast,delete keyの３つが考えられる
        else if (com[0]=='d')
        {
            //deleteFirst,deleteLastは６文字以上である
            if (strlen(com)>6)
            {
                //６文字目がFならFirst
                if (com[6]=='F')deleteFirst();
                //６文字目がLならLast
                else if (com[6]=='L')deleteLast();
            }
            else
            {
                //nd : del回数？
                deleteKey(key);nd++;
            }
            //連結リストのsize-1
            size--;
        }
        
    }
    
    printList();

    return 0;
}



