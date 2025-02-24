#include <cstdio>
#include <iostream>
using namespace std;
int n, m = 0, p, q, ans;
string temp;
int a[1029][10003], w[1029][1029];
int f(int x, int y)
{
    ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans += w[x][i] * a[i][y];
    }
    return ans;
}
void solve(int q)
{
    for (int i = 1; i <= q; ++i)
    {
        for (int j = 1; j <= q; ++j)
        {
            w[i + q][j + q] = -w[i][j];
            w[i + q][j] = w[i][j];
            w[i][j + q] = w[i][j];
        }
    }
}
int main()
{
    scanf("%d %d", &m, &n);
    w[1][1] = 1;
    int q = 1;
    while (q < m)
    {
        solve(q);
        q *= 2;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> temp;
        for (int j = 0; j < n; ++j)
        {
            a[i][j + 1] = temp[j] - '0';
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", f(i, j));
        }
        printf("\n");
    }
    return 0;
}