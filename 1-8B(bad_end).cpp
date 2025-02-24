#include <cstdio>
#pragma GCC optimize(3)
using namespace std;
int n, a[100005] = {0}, c[100005] = {0};
int b[100005] = {0};
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] >= c[i - 1])
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = c[i - 1];
        }
        if (a[i] > c[i - 1] + 1)
        {
            printf("-1\n");
            return 0;
        }
    }
    b[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int index = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j] == a[i] - 1)
            {
                index = j;
                break;
            }
        }
        b[i] = b[index] + 1;
        for (int j = 1; j <= i - 1; ++j)
        {
            if (b[j] >= b[i])
            {
                b[j]++;
            }
        }
    }
    for (int k = 1; b[k] != 0; ++k)
    {
        printf("%d ", b[k]);
    }
    return 0;
}