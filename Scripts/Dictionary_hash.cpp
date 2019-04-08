#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL (-1)
#define L 14

//n<=10^6なので最大でそれだけ辞書に追加される可能性がある
//Mが10^6に近い素数なのはそういうことか
//ちなみに1,046,527は素数だが、10^6より大きい最小の素数ではないみたい
char H[M][L];

//char->int
int getChar(char ch)
{
    if(ch=='A')return 1;
    else if(ch=='C')return 2;
    else if (ch=='G')return 3;
    else if(ch=='T')return 4;
    else return 0;
}

//strig -> int key
//long long型およびunsigned long long型は、64ビット以上の値を表現できる
long long getKey(char str[])
{
    long long sum=0,p=1,i;
    for (i=0;i<strlen(str);i++)
    {
        sum+=p*(getChar(str[i]));
        p*=5;
    }
    return sum;
}
/*
getKeyの処理を考える
たとえば'AGC'が入ったとして順番に処理する
- p=1,sum=0
getChar('A')=1
sum+=1*1
- p=5,sum=1
getChar('G')=3
sum+=5*3
- p=25,sum=1+5*3
getChar('C')=2
sum+=25*2

- sum=1+5*3+25*2=66

これをかいてみて分かったが、文字列は最大で12文字続く
このとき最後にはp=5^11がかかるわけで
5^11=48,828,125>10^7
たしかにこれだけあれば異なる文字列でkeyが被ることもないか
まず文字数でかなり位置取りが変わる
そのうえで同じ文字数でもさまざまにズレることができる
*/

//hash1関数
int h1(int key){return key%M;}
//hash2関数
int h2(int key){return 1+(key%(M-1));}

int find(char str[])
{
    long long key,i,h;
    key=getKey(str);
    for(i = 0; ;i++)
    {
        h=(h1(key)+i*h2(key))%M;
        //strcmp:文字列s1と文字列s2を比較します
        //s1 > s2 で正の値、s1 < s2 で負の値、s1 = s2で 0 を返す。この大小関係は一般に文字コード順による。
        if(strcmp(H[h],str)==0)return 1;
        else if(strlen(H[h])==0)return 0;
    }
    return 0;
}

int insert(char str[])
{
    long long key,i,h;
    key=getKey(str);
    for( i = 0;; i++)
    {
        h=(h1(key)+i*h2(key))%M;
        //豆知識；c++では0 とstrのfalseが偽でそれ以外が真
        //H[h]==strのときreturn 1;
        //それ以外はstrcpyしてinsert
        if(strcmp(H[h],str)==0)return 1;//衝突の確認
        else if(strlen(H[h])==0)//H[h]が空、つまり衝突の確認
        {   
            //char *strcpy(char *s1, const char *s2);
            //文字型配列 *s1 に文字列 *s2 を '\0' までコピーします。'\0' もコピーするので s1 はその分も考えて大きさを宣言しておかなければなりません。
            //もし、s1 と s2 が重なっている場合には動作は未定義となります。
            // char *s1　：　複写先の文字型配列
            // const char *s2　：　複写する文字列
            // 【戻り値】
            // s1の値。つまり返却値はコピー後の文字列を指す。
            strcpy(H[h],str);//H[h]<-str
            return 0;
        }
    }
    return 0;
    
}

int main()
{
    int i,n,h;
    char str[L],com[9];
    
    for(i=0;i<M;i++)H[i][0]='\0';
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s %s",com,str);

        if(com[0]=='i')
        {
            insert(str);
        }
        else
        {
            if(find(str))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
            
        }
        
    }
    return 0;
}














// 値とboolについては次のでも試してください
// int main(void){

//     if(-5)return 1;//if内を好きに変えてね
    
//     return 0;
// }