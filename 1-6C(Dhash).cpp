#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int a[1007][999];
int b[10][10];
int c[9][9];
int average(int i, int j, int x, int y)
{
    int ave, sum = 0;
    for (int p = (i - 1) * x + 1; p <= i * x; ++p)
    {
        for (int q = (j - 1) * y + 1; q <= j * y; ++q)
        {
            sum += a[p][q];
        }
    }
    ave = 72 * sum / (m * n);
    return ave;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) // 输入
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int x = n / 8, y = m / 9;
    for (int i = 1; i <= 8; ++i) // 计算平均值
    {
        for (int j = 1; j <= 9; ++j)
        {
            b[i][j] = average(i, j, x, y);
        }
    }
    for (int i = 1; i <= 8; ++i) // 二进制赋值
    {
        for (int j = 2; j <= 9; ++j)
        {
            if (b[i][j] > b[i][j - 1])
            {
                c[i][j - 1] = 1;
            }
            else
            {
                c[i][j - 1] = 0;
            }
        }
    }
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            int num = 0;
            num = 8 * c[i][4 * j - 3] + 4 * c[i][4 * j - 2] + 2 * c[i][4 * j - 1] + c[i][4 * j];
            switch (num)
            {
            case (15):
                printf("F");
                break;
            case (14):
                printf("E");
                break;
            case (13):
                printf("D");
                break;
            case (12):
                printf("C");
                break;
            case (11):
                printf("B");
                break;
            case (10):
                printf("A");
                break;
            case (9):
                printf("9");
                break;
            case (8):
                printf("8");
                break;
            case (7):
                printf("7");
                break;
            case (6):
                printf("6");
                break;
            case (5):
                printf("5");
                break;
            case (4):
                printf("4");
                break;
            case (3):
                printf("3");
                break;
            case (2):
                printf("2");
                break;
            case (1):
                printf("1");
                break;
            case (0):
                printf("0");
                break;
            }
        }
    }
    return 0;
}