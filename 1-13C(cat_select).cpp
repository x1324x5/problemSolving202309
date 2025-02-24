#include <cstdio>
using namespace std;
int n, k, a[25];
const long long INF = 0x3f3f3f3f3f3f3f3fll;
long long po[26], ans = -INF, val[25], vis[25], temp = 0;
void solve(int depth, int down)
{
    if (depth == k + 1)
    {
        temp = 0;
        for (int j = 1; j <= k; j++)
        {
            temp += val[j] * po[k - j];
        }
        if (temp > ans)
        {
            ans = temp;
        }
        return;
    }
    for (int i = down; i <= n; ++i)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        vis[i] = 1;
        val[depth] = a[i];
        solve(depth + 1, i + 1);
        vis[i] = 0;
    }
    return;
}
int main()
{
    scanf("%d %d", &n, &k);
    po[0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        po[i] = 3 * po[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    solve(1, 1);
    printf("%lld", ans);
    return 0;
}