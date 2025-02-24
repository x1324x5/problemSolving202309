#include <cstdio>
#pragma GCC optimize(2)
using namespace std;
int n, m, K, op;          // n是钩子数，m是衣架个数，K是运行次数
int **p = new int *[n](); // 行代表不同的钩子，每一列代表钩子下面含有的衣架
int check(int **p, int k) // 整个表中有没有x存在，有就返回行所在的编号
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (p[i][j] == k)
            {
                return i;
                break;
            }
        }
    }
    return -1;
}
int count(int **p, int q) // 表中的第q行有几个元素

{
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        if (p[q - 1][i] != 0)
        {
            count++;
        }
    }
    return count;
}
int line(int **p, int q, int x) // 表中第q行里面x的列编号是多少
{
    for (int i = 0; i < m; ++i)
    {
        if (p[q - 1][i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < m; ++i)
    {
        p[i] = new int[1000](); // 创建每个钩子下的空间
    }
    for (int i = 1; i <= K; ++i)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            int x = 0, temp = 0;
            scanf("%d", &x);
            temp = check(p, x);
            if (temp >= 0) // 存在就输出行数
            {
                printf("%d", temp + 1);
            }
            else
            {
                printf("free hanger.");
            }
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (check(p, x) == -1)
            {
                int temp = count(p, y); // 如果没在表里面，就添加到对应行的末尾
                p[y - 1][temp] = x;
            }
            else
            {
                int num = check(p, x);           // x在编号为num的行里面
                int temp = count(p, num + 1);    // 编号为num行里面有多少个元素
                int temp2 = line(p, num + 1, x); // 元素x在这一行中的列编号
                int ytemp = count(p, y);         // 目标行现有几个元素
                for (int i = 1; i <= temp - temp2; ++i)
                {
                    p[y - 1][ytemp + i - 1] = p[num][temp2 + i - 1]; // 对应替换到新的行里面
                    p[num][temp2 + i - 1] = 0;                       // 删除原来的元素
                }
            }
        }
    }
    return 0;
}