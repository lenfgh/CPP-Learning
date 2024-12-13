// This is the copied from https://blog.csdn.net/wangfengjs/article/details/8363227
// Created by FUGUO on 2024/11/4.
//
#include <cstdio>
int main()
{
    int a[100][100],N,j=0,k=0,i,S=0;
    scanf("%d",&N);
    int tag_right=0;//转向标志
    int tag_left=0;//转向标志
    int tag_up=0;//转向标志1表示不可以转向
    int tag_down=0;//转向标志表示可以转向
    for(i=1;i<=N*N;i++)
    {
        if(j>=0&&k>=0)a[j][k]=i;
        if(j==0&&k<N-1&&tag_right==0){k++;tag_right=1;tag_down=0;}//向右
        else if(k==0&&j<N-1&&tag_down==0){j++;tag_down=1;tag_right=0;}//向左
        else if(tag_down==1){k++;j--;}//向右上
        else if(tag_right==1){k--;j++;}//向左下
    }
    j=N-1;k=N-1;
    for(i=1;i<=N;i++) S=S+i;
    for(i=N*N;i>S;i--)
    {
        if(j>=0&&k>=0)a[j][k]=i;
        if(j==N-1&&tag_left==0&&k>0){k--;tag_left=1;tag_up=0;}//向左
        else if(k==N-1&&tag_up==0&&j>0){j--;tag_left=0;tag_up=1;}//向上
        else if(tag_left==1){k++;j--;}//向右上
        else if(tag_up==1){k--;j++;}//向左下
    }
    if(N>1)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
            {
                if(k<N-1)
                    printf("%2d ",a[j][k]);
                else
                    printf("%2d",a[j][k]);
            }
            printf("\n");
        }
    }
    else
        printf("%2d\n",N);
    return 0;
}