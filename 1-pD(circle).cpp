#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int n;
long double cx = 0, cy = 0, ro = 0, dis;
struct poi
{
    long double x, y;
};
poi A[205];
void circle(poi p, poi q, poi r)
{
    long double d1 = (pow(q.x, 2) + pow(q.y, 2)) - pow(p.x, 2) - pow(p.y, 2);
    long double d2 = (pow(r.x, 2) + pow(r.y, 2)) - pow(q.x, 2) - pow(q.y, 2);
    long double fm = 2 * ((r.y - q.y) * (q.x - p.x) - (q.y - p.y) * (r.x - q.x));
    cx = ((r.y - q.y) * d1 - (q.y - p.y) * d2) / fm;
    cy = ((q.x - p.x) * d2 - (r.x - q.x) * d1) / fm;
    ro = sqrt(pow(p.x - cx, 2) + pow(p.y - cy, 2));
    return;
}
bool incir(poi a)
{
    dis = sqrt(pow(a.x - cx, 2) + pow(a.y - cy, 2));
    if (dis * dis <= ro * ro + 1e-5)
    {
        return true;
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%Lf %Lf", &A[i].x, &A[i].y);
    }
    ro = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!incir(A[i]))
        {
            cx = A[i].x;
            cy = A[i].y;
            ro = 0;
            for (int j = 1; j <= i - 1; ++j)
            {
                if (!incir(A[j]))
                {
                    cx = (A[i].x + A[j].x) / 2;
                    cy = (A[i].y + A[j].y) / 2;
                    ro = sqrt(pow(A[i].x - A[j].x, 2) + pow(A[i].y - A[j].y, 2)) / 2;
                    for (int k = 1; k <= j - 1; ++k)
                    {
                        if (!incir(A[k]))
                        {
                            circle(A[i], A[j], A[k]);
                        }
                    }
                }
            }
        }
    }
    printf("%.10Lf\n%.10Lf %.10Lf", ro, cx, cy);
    return 0;
}