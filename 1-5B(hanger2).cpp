#include <cstdio>
#pragma GCC optimize(3)
using namespace std;
int n, m, K, op, x, y;
struct rack
{
    int pre = 0, next = 0;
};
rack a[2001];
int main()
{
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < K; ++i)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            if (a[x].pre == 0)
            {
                printf("free hanger.\n");
            }
            else
            {
                while (a[x].pre <= m)
                {
                    x = a[x].pre;
                }
                printf("%d\n", a[x].pre - m);
            }
        }
        else
        {
            scanf("%d%d", &x, &y);
            if (a[x].pre != 0)
            {
                int put = m + y;
                a[a[x].pre].next = 0;
                a[x].pre = 0;
                while (a[put].next != 0)
                {
                    put = a[put].next;
                }
                a[x].pre = put;
                a[put].next = x;
            }
            else //=0
            {

                int put = m + y;
                while (a[put].next != 0)
                {
                    put = a[put].next;
                }
                a[put].next = x;
                a[x].pre = put;
            }
        }
    }
    return 0;
}