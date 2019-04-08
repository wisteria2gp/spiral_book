#include <stdio.h>

int A[1000000],n;

//BinarySearch
int binarySearch(int key)
{
    //leftは探索範囲、最左端であるのに対し
    int left=0;
    //配列Aのindexは0-n-1であり
    //right=n なのでright自体は探索範囲最右端より1個右であることに注意
    int right=n;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(key==A[mid])return 1;//find key!
        //上で述べた通りleftは左端自体なのでmidより1個ずらす
        if(key>A[mid])left=mid+1;//next search right side
        //rightは右端の1個後ろなのでmidにするだけで1つ範囲が狭まることに注意
        else if(key<A[mid])right=mid;//next search left side

    }
    return 0;
}

int main()
{
    int i,q,k,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&k);
        if(binarySearch(k))sum++;
    }

    printf("%d\n",sum);

    return 0;
}