#include <cstdio>
using namespace std;
int n, m, T, op, t, num;
struct obj
{
    int outtime = 0, time = 0, ifwait = 0, ifout = 0;
};
obj good[1005];
int main()
{
    scanf("%d%d%d", &n, &m, &T);
    if (m == 0) // 简单情况直接输出
    {
        for (long long i = 1; i <= n; i++)
        {
            printf("%d ", T);
        }
        return 0;
    }
    else
    {
        for (int q = 1; q <= n; q++)
        {
            good[q].outtime = T;
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &op, &t);
            if (op == 1) // 清空等待队列
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (t >= good[j].outtime)
                    {
                        good[j].ifout = 1;
                    }
                }
                for (int j = 1; j <= n; ++j)
                {
                    if (good[j].ifwait == 1)
                    {
                        good[j].outtime = T + t;
                        good[j].ifwait = 0;
                    }
                }
            }
            else // 把没有出去的丢到等待队列里面，相当于已经走过的时间要清零
            {
                scanf("%d", &num);
                for (int j = 1; j <= n; ++j)
                {
                    if (t >= good[j].outtime)
                    {
                        good[j].ifout = 1;
                    }
                }
                if (good[num].ifwait == 0 && good[num].ifout == 0)
                {
                    good[num].ifwait = 1;
                    good[num].outtime = 1000000;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", good[i].outtime);
    }
    return 0;
}