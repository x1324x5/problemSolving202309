#include <cstdio>
#include <unordered_map>
using namespace std;
int a[505] = {}, A[505] = {}, B[505] = {};
int n = 0, m = 0, k = 0, T = 0;
int fun(int x)
{
    int ans = 0;
    ans = (x * a[n] + a[n - 1]) % 10007;
    for (int i = n - 2; i >= 0; i--)
    {
        ans = (ans * x + a[i]) % 10007;
    }
    return ans;
}
bool check(int x)
{
    for (int i = 1; i <= k; ++i)
    {
        if (x == B[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {

        unordered_map<int, bool> jiancha;
        scanf("%d%d%d", &n, &m, &k);
        if (n != 0)
        {
            for (int i = 0; i <= n; ++i)
            {
                scanf("%d", &a[i]);
            }
            for (int i = 1; i <= m; ++i)
            {
                scanf("%d", &A[i]);
                A[i] = fun(A[i]);
            }
            for (int i = 1; i <= k; ++i)
            {
                scanf("%d", &B[i]);
            }
            int count = 0;
            for (int i = 1; i <= m; ++i)
            {
                if (check(A[i]))
                {
                    if (jiancha[A[i]] == 0)
                    {
                        jiancha[A[i]] = 1;
                        count++;
                    }
                }
            }
            if (count == k)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            scanf("%d", &a[0]);
            for (int i = 1; i <= m; ++i)
            {
                scanf("%d", &A[i]);
                A[i] = a[0];
            }
            for (int i = 1; i <= k; ++i)
            {
                scanf("%d", &B[i]);
            }
            int count = 0;
            for (int i = 1; i <= m; ++i)
            {
                if (check(A[i]))
                {
                    if (jiancha[A[i]] == 0)
                    {
                        jiancha[A[i]] = 1;
                        count++;
                    }
                }
            }
            if (count == k)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}