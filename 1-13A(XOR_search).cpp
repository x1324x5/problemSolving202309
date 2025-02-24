#include <cstdio>
using namespace std;
const int N = 2e7 + 5;
const int modd = 998244353;
long long T = 0, n = 0, a[N], ans = 0;
int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            a[i] ^= a[i - 1];
        }
        for (int i = 0; i < 31; i++)
        {
            long long B[2] = {0, 0};
            for (int j = 0; j <= n; ++j)
            {
                B[(a[j] >> i) & 1]++;
            }
            ans += ((B[0] * B[1]) % modd) * (1 << i);
            ans %= modd;
        }
        printf("%lld\n", ans);
    }
}