#include <cstdio>
using namespace std;
int n, m;
int a[200005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int count = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            count++;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int b, s;
        scanf("%d%d", &b, &s);
        if (b == 1)
        {
            int temp = 0;
            if (a[1] > a[2])
            {
                temp = 1;
            }
            a[b] = s;
            if (a[1] <= a[2] && temp == 1)
            {
                count--;
            }
            else if (a[1] > a[2] && temp == 0)
            {
                count++;
            }
        }
        else if (b == n)
        {
            int temp = 0;
            if (a[n - 1] > a[n])
            {
                temp = 1;
            }
            a[b] = s;
            if (a[n - 1] <= a[n] && temp == 1)
            {
                count--;
            }
            else if (a[n - 1] > a[n] && temp == 0)
            {
                count++;
            }
        }
        else
        {
            int temp = 0, temp2 = 0;
            if (a[b] > a[b + 1])
            {
                temp = 1;
            }
            if (a[b - 1] > a[b])
            {
                temp2 = 1;
            }
            a[b] = s;
            if (a[b] <= a[b + 1] && temp == 1)
            {
                count--;
            }
            else if (a[b] > a[b + 1] && temp == 0)
            {
                count++;
            }
            if (a[b - 1] <= a[b] && temp2 == 1)
            {
                count--;
            }
            else if (a[b - 1] > a[b] && temp2 == 0)
            {
                count++;
            }
        }
        if (count == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}