#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 100005
using namespace std;
long double min(long double a, long double b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
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
    long double R, a, c;
    int n;
    cin >> n >> R >> a >> c;
    int d[N] = {}, x[N] = {}, drop[N] = {};
    double t = sqrt(-c / a);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= a * pow(x[i] + R, 2) + c)
        {
            drop[i] = sqrt(t);
        }
        else if (d[i] > a * pow(max(x[i] - R, 0), 2) + c)
        {
            drop[i] = max(0, x[i] - R);
        }
        else
        {
            drop[i] = min(x[i] + R, t);
        }
    }
    sort(drop, drop + n + 2);
    printf("%.3f ", drop[1]);
    printf("%.3f ", drop[2]);
    printf("%.3f ", drop[3]);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] < drop[1] + R && x[i] >= drop[1] - R)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}