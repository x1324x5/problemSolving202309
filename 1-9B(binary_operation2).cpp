#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, q, a[1000005] = {}, t[1000005] = {}, x = 0;
int decide(int i)
{
    int ans = 0;
    for (int j = 1; j <= n; ++j)
    {
        int temp = (t[j] >> i) & 1;
        switch (a[j])
        {
        case (1):
            ans = ans | temp;
            break;
        case (2):
            ans = ans & temp;
            break;
        case (3):
            ans = ans ^ temp;
            break;
        }
    }
    if (ans == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    if (q == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            char op[3] = "";
            scanf("%s", &op);
            scanf("%d", &t[i]);
            if (strcmp(op, "OR") == 0) // 将输入的运算符用123来代表
            {
                a[i] = 1;
            }
            else if (strcmp(op, "AND") == 0)
            {
                a[i] = 2;
            }
            else
            {
                a[i] = 3;
            }
        }
        for (int i = 1; i <= q; ++i)
        {
            x += decide(i - 1) * pow(2, i - 1); // 输出结果对应的十进制数
        }
        printf("%d", x);
    }
    return 0;
}