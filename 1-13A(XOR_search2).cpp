#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e6 + 5;
const int modd = 998244353;
long long n, ans = 0, T = 0;
int a[N];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i] ^= a[i - 1];
        }
        for (int d = 0; d < 31; d++)
        {
            int c[2] = {0, 0};
            for (int i = 0; i <= n; i++)
            {
                ++c[a[i] >> d & 1];
            }
            ans += (1 << d) * ((c[0] * c[1]) % modd);
            ans %= modd;
        }
        printf("%ld\n", ans);
    }
    return 0;
}