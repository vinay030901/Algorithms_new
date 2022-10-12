#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int (*arr)[m+1] = calloc(n+1, sizeof *arr);
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    arr[i][j] =0;
    for(int i=0;i<k;i++)
    {
        int r,c1,c2;
        scanf("%d%d%d",&r,&c1,&c2);
        for(int i=c1;i<=c2;i++)
        arr[r][i]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(arr[i][j]==0) cnt+=1;
    printf("%d\n",cnt);
}