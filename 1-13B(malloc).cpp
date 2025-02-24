#include <cstdio>
#include <vector>
using namespace std;
vector<int> m, p, s;
int n, k = 0, opt = 0;
void memset()
{
    int x = 0, y = 0, v = 0, c = 0;
    bool flag = 0;
    scanf("%d %d %d %d", &x, &y, &v, &c);
    int count = p[x] + y;
    if (c == 0)
    {
        printf("true\n");
        return;
    }
    if (p[x] + y >= p[n] || p[x] + y < 0 || p[x] + y + c - 1 >= p[n])
    {
        printf("overflow\n");
        return;
    }
    if (y < 0)
    {
        flag = 1;
    }
    if ((x != n - 1 && p[x] + y > p[x + 1] - 1) || p[x] + y + c > p[x + 1])
    {
        flag = 1;
    }
    for (int i = 0; i < c; ++i)
    {
        s[count + i] = v;
    }
    if (flag == 1)
    {
        printf("wtrue\n");
    }
    else
    {
        printf("true\n");
    }
    return;
}
void strcpy()
{
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0, cnt1 = 1, cnt2 = 1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    bool flag = 0;
    int count = p[x0] + y0;
    if (p[x0] + y0 < 0 || p[x0] + y0 >= p[n] || p[x1] + y1 < 0 || p[x1] + y1 >= p[n])
    {
        printf("overflow\n");
        return;
    }
    if (y0 < 0 || y1 < 0)
    {
        flag = 1;
    }
    while (s[count] != 0)
    {
        if (count == p[n] - 1)
        {
            printf("overflow\n");
            return;
        }
        count++;
        cnt1++;
        if (count >= p[x0 + 1])
        {
            flag = 1;
        }
    }
    if (cnt1 + p[x1] + y1 - 1 >= p[n])
    {
        printf("overflow\n");
        return;
    }
    if ((p[x1] + y1 >= p[x0] + y0 && p[x1] + y1 <= p[x0] + y0 + cnt1 - 1) ||
        (p[x1] + y1 + cnt1 - 1 >= p[x0] + y0 && p[x1] + y1 <= p[x0] + y0))
    {
        printf("overwrite\n");
        return;
    }
    for (int i = 0; i < cnt1; ++i)
    {
        s[p[x1] + y1 + i] = s[p[x0] + y0 + i];
        if (p[x1] + y1 + i >= p[x1 + 1] || p[x0] + y0 + i >= p[x0 + 1])
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("wtrue\n");
    }
    else
    {
        printf("true\n");
    }
    return;
}
void strlen()
{
    int x = 0, y = 0, cnt = 0;
    bool flag = 0; // 用于判断是否越界
    scanf("%d %d", &x, &y);
    int count = p[x] + y;
    if (p[x] + y > p[n] - 1 || p[x] + y < 0) // 超出最后一位或超出开头就非法表示
    {
        printf("overflow\n");
        return;
    }
    if (y < 0)
    {
        flag = 1;
    }
    if (p[x] + y > p[x + 1] - 1)
    {
        flag = 1;
    }
    while (s[count] != 0)
    {
        if (count == p[n] - 1)
        {
            printf("overflow\n");
            return;
        }
        count++;
        cnt++;
        if (count > p[x + 1] - 1)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("w%d\n", cnt);
    }
    else
    {
        printf("%d\n", cnt);
    }
    return;
}
int main()
{
    scanf("%d", &n);
    m.resize(n, 0);
    p.resize(n + 2, 0); // 分配内存大小
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &m[i]);
        p[i + 1] = p[i] + m[i];
    } // p[x]作为前缀和，表示这个字符数组（包含这一个）及前面的字符的数量总数
    p[n + 1] = p[n];
    s.resize(p[n], 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m[i]; ++j)
        {
            scanf("%d", &s[p[i] + j]); // 利用p[x]+j的形式定位每一位字符
        }
    }
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            memset();
            break;
        case 1:
            strcpy();
            break;
        case 2:
            strlen();
            break;
        default:
            break;
        }
    }
    return 0;
}