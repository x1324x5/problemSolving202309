#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int a[(int)1e6 + 1], b[(int)1e6 + 1], A[(int)1e6 + 1], B[(int)1e6 + 1];
int n = 0, ans = 1;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    if (n == 1)
    {
        printf("%d", a[0]);
        return 0;
    }
    if (n == 2)
    {
        printf("%d", a[0] > a[1] ? a[0] : a[1]);
        return 0;
    }
    A[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        A[i] = gcd(A[i - 1], a[i]);
    }
    B[0] = a[n - 1];
    for (int i = 1; i < n; ++i)
    {
        B[i] = gcd(B[i - 1], a[n - 1 - i]);
    }
    b[0] = B[n - 2];
    b[n - 1] = A[n - 2];
    for (int i = 1; i < n - 1; ++i)
    {
        b[i] = gcd(A[i - 1], B[n - 2 - i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (ans < b[i])
        {
            ans = b[i];
        }
    }
    printf("%d", ans);
    return 0;
}