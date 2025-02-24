#include <cstdio>
#include <cmath>
using namespace std;
long long A[11][11], B[11][11], C[11][11];
int r, n, m, l;
long long count(long long A[11][11], int r)
{
    if (r == 1)
    {
        return A[1][1];
    }
    else if (r == 2)
    {
        return A[1][1] * A[2][2] - A[1][2] * A[2][1];
    }
    else
    {
        long long ans = 0;
        for (int i = 1; i <= r; ++i)
        {
            long long temp[11][11] = {};
            for (int p = 1; p <= r - 1; ++p)
            {
                for (int q = 1; q <= r - 1; ++q)
                {
                    if (q < i)
                    {
                        temp[p][q] = A[p + 1][q];
                    }
                    else
                    {
                        temp[p][q] = A[p + 1][q + 1];
                    }
                }
            }
            if (i & 1)
            {
                ans += count(temp, r - 1) * A[1][i];
            }
            else
            {
                ans -= count(temp, r - 1) * A[1][i];
            }
        }
        return ans;
    }
}
long long multi(long long B[11][11], long long C[11][11], int i, int j)
{
    int ans = 0;
    for (int k = 1; k <= m; ++k)
    {
        ans += B[i][k] * C[k][j];
    }
    return ans;
}
int main()
{
    scanf("%d", &r);
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= r; ++j)
        {
            scanf("%ld", &A[i][j]);
        }
    }
    printf("%ld\n", count(A, r));
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%ld", &B[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= l; ++j)
        {
            scanf("%ld", &C[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= l; ++j)
        {
            printf("%ld ", multi(B, C, i, j));
        }
        printf("\n");
    }
}