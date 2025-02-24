#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 100005
using namespace std;
long double min(long double a, long double b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
long double max(long double a, long double b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n, R, a, c;
    scanf("%d%d", &n, &R);
    scanf("%d%d", &a, &c);
    long long d[N] = {}, x[N] = {};
    double dro[N] = {};
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    long double t = -c / a;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= a * pow(x[i] + R, 2) + c)
        {
            dro[i] = sqrt(t);
        }
        else if (d[i] > a * pow(max(x[i] - R, 0), 2) + c)
        {
            dro[i] = max(0, x[i] - R);
        }
        else
        {
            dro[i] = min(x[i] + R, sqrt(t));
        }
    }
    sort(dro, dro + n + 1);
    printf("%.3f ", dro[1]);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] < dro[1] + R && x[i] >= dro[1] - R)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}