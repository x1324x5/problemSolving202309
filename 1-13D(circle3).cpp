#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int d[N], n, circle[N] = {0}, ans = 0, ifvis[N] = {0}, cnt = 0;
void dfs(int x)
{
    if (ifvis[x] == cnt)
    {
        if (d[x] == x)
        {
            circle[x] = 1;
        }
        else
        {
            int round = x;
            circle[round] = 1;
            round = d[round];
            while (round != x)
            {
                circle[round] = 1;
                round = d[round];
            }
        }
    }
    if (ifvis[x])
    {
        return;
    }
    ifvis[x] = cnt;
    dfs(d[x]);
}
int main()
{
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!ifvis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (circle[i] == 1)
        {
            ans++;
        }
    }
    printf("%d", ans);
}