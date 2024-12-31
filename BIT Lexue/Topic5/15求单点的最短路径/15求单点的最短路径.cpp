//
// Created by FUGUO on 2024/12/31.
// copied from CDSN

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f;
int road[1010][1010], d[1010];
bool vis[1010];
int n, m, num = 0;

void dijkstra(int s)//dijkstra算法
{
    for (int i = 0; i < n; i++)
    {
        d[i] = road[s][i];
        vis[i] = false;
    }
    d[s] = 0;
    vis[s] = true;
    for (int i = 0; i < n; i++)
    {
        int temp = inf, v;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && temp > d[j])
            {
                temp = d[j];
                v = j;
            }
        }
        if (temp == inf)
            break;
        vis[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[v] + road[v][j] < d[j])
            {
                d[j] = d[v] + road[v][j];
            }
        }
    }
}
int main()
{
    int x, y, dis;
    char a, b, c;
    scanf("%d,%d,%c", &m, &n, &c);
    getchar();                  //读取换行符
    for (int i = 0; i < n; i++)//初始化
    {
        for (int j = 0; j < n; j++)
        {
            road[i][j] = (i == j) ? 0 : inf;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("<%c,%c,%d>", &a, &b, &dis);
        getchar();
        x = a - 'a';//把字符转化为数字来算
        y = b - 'a';
        if(road[x][y]>dis)
            road[x][y]= dis;
    }
    num = c - 'a';
    dijkstra(num);
    for (int i = 0; i < m; i++)
    {
        printf("%c:%d\n", i + 'a', d[i]);//记得转回字符
    }
    //system("pause");
    return 0;
}
