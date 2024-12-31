// This is the solution of https://lexue.bit.edu.cn/mod/programming/history.php?id=476071
// Created by FUGUO on 2024/12/31.
// copied form CDSN
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
//最小生成树，kruskal算法

struct node
{
    int x;
    int y;
    int dis;
}road[5500];
bool operator<(const node &A, const node &B)//自定义排序规则，sort时会自动采用
{
    return A.dis < B.dis;
}
int n = 0, m = 0;
int tree[1010];

//并查集
void init()
{
    for (int i = 0; i <= n; i++)
        tree[i] = i;
}
int find(int n)
{
    if (tree[n] == n)
        return n;
    else
        return tree[n] = find(tree[n]);
}
int judge(int x, int y)//判断是否成环，不成环则返回1
{
    int a = find(x);
    int b = find(y);
    if (a != b)
    {
        tree[a] = b;
        return 1;
    }
    else
        return 0;
}
void kruskal()
{
    int side = 0;//选出的边数
    int sum = 0;//总的开销
    init();
    sort(road, road + m);//全局排序
    for (int i = 0; i < m; i++)
    {
        if (judge(road[i].x, road[i].y))
        {
            side++;
            sum += road[i].dis;
        }
        if (side == n - 1)
            break;
    }
    if (side != n - 1)  //选不出n-1条边，则无法构成最小生成树
        cout << "-1" << endl;
    else
        cout << sum << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> road[i].x >> road[i].y >> road[i].dis;

    kruskal();
    //system("pause");
    return 0;
}