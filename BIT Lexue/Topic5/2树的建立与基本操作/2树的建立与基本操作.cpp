// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=476063
// Created by FUGUO on 2024/12/23.
//
#include<iostream>
#include<cstdio>

int main() {
    char inputChar, label[100];  //定义输入字符和标签数组
    int count = 0, level[100], degree[100] = { 0 }, degreeCount[100] = { 0 }; //定义计数器、等级数组、度数组和度计数数组
    int currLevel = -1, i, j, maxDegree = 0; //定义当前等级、循环变量和最大度

    while (1)
    {
        inputChar = getchar();
        if (inputChar == '\n') break;
        switch (inputChar)
        {
            case '(': currLevel++; break; //左括号，当前等级增加
            case ')': currLevel--; break; //右括号，当前等级降低
            case ',': break; //逗号，不改变等级
            default:
                count++;
                label[count] = inputChar;
                level[count] = currLevel;
                break; //其他字符，当作节点标签，将其存入数组，并标记其等级
        }
    }

    //打印树状结构图
    for (i = 1; i <= count; i++)
    {
        for (j = 0; j < level[i]; j++)
            printf("    ");//对于每一层，打印相应的缩进
        printf("%c\n", label[i]); //打印节点标签
    }

    //计算每个节点的度
    for (i = 1; i <= count; i++)
    {
        for (j = i + 1; j <= count; j++)
        {
            if (level[j] == level[i]) break; //如果相同等级的节点出现，跳出
            if (level[j] == level[i] + 1) //如果下一层级的节点出现，该节点的度加1
                degree[i]++;
        }
    }

    //找出最大的度
    for (i = 1; i <= count; i++)
    {
        if (degree[i] > maxDegree)
            maxDegree = degree[i];
    }

    //计算每个度的节点数
    for (i = 1; i <= count; i++)
        degreeCount[degree[i]]++;

    //输出度和节点数
    printf("Degree of tree: %d\n", maxDegree);
    for (i = 0; i <= maxDegree; i++)
        printf("Number of nodes of degree %d: %d\n", i, degreeCount[i]);

    return 0;
}