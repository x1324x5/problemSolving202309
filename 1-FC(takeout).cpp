#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
struct poi
{
    double x, y;
};
poi peo[10005];
poi turn[10005];
int main()
{
    int n, k = 0;
    double a, b, c;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf %lf", &peo[i].x, &peo[i].y);
    }
    scanf("%lf %lf %lf", &a, &b, &c);
    double len = 0, q = a * a + b * b;
    peo[0].x = 0;
    peo[0].y = 0;
    peo[n + 1].x = 0;
    peo[n + 1].y = 0;
    for (int i = 0; i <= n; ++i)
    {
        if ((a * peo[i + 1].x + b * peo[i + 1].y + c) * (a * peo[i].x + b * peo[i].y + c) < 0)
        {
            len += sqrt(pow(peo[i].x - peo[i + 1].x, 2) + pow(peo[i].y - peo[i + 1].y, 2));
        }
        else
        {
            double xt, yt;
            xt = (-2 * a * b * peo[i].y - (a * a - b * b) * peo[i].x - 2 * a * c) / q;
            yt = ((a * a - b * b) * peo[i].y - 2 * a * b * peo[i].x - 2 * c * b) / q;
            double m = (peo[i + 1].y - yt) / (peo[i + 1].x - xt);
            double o = yt - m * xt;
            turn[k].x = -(b * o + c) / (a + b * m);
            turn[k].y = turn[k].x * m + o;
            len += sqrt(pow(xt - peo[i + 1].x, 2) + pow(yt - peo[i + 1].y, 2));
            k++;
        }
    }
    printf("%lf\n%d\n", len, k);
    for (int i = 0; i < k; ++i)
    {
        printf("%lf %lf\n", turn[i].x, turn[i].y);
    }
    return 0;
}