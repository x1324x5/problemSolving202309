#include <cstdio>
using namespace std;
long long n, m, T;
long long op = 0, t = 0;
struct obj
{
    long long ifout = 0, outtime = 0, ifwait = 0, time = 0, lasttime = 0;
    // 标记是否走完，走出去的时间，是否在等待中，已经走过的时间，上一次更新的时间
};
obj good[2000];
long long temp = 0;
long long num = 0;
void update(long long t, long long last) // 根据时间更新
{
    for (long long i = 1; i <= n; ++i) // 每个物品
    {
        if (good[i].ifout == 0 && good[i].ifwait == 0) // 没在等待并且没出去
        {
            temp = good[i].time;
            good[i].time += t - last;
            good[i].lasttime = t;
            if (good[i].time >= T) // 走完的情况
            {
                good[i].outtime = T - temp + last;
                good[i].ifout = 1;
            }
        }
    }
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &T);
    long long last = 0;
    if (m == 0) // 简单情况直接输出
    {
        for (long long i = 1; i <= n; i++)
        {
            printf("%lld ", T);
        }
        return 0;
    }
    else
    {
        for (long long i = 1; i <= m - 1; ++i)
        {

            scanf("%lld%lld", &op, &t);
            if (op == 1) // 清空等待队列
            {
                update(t, last);
                for (long long j = 1; j <= n; ++j)
                {
                    if (good[j].ifwait == 1)
                    {
                        good[j].ifwait = 0;
                    }
                }
            }
            else // 把没有出去的丢到等待队列里面，相当于已经走过的时间要清零
            {
                update(t, last);
                num = 0;
                scanf("%lld", &num);
                if (good[num].ifout == 0)
                {
                    good[num].ifwait = 1;
                    good[num].time = 0;
                }
            }
            last = t;
        }
        scanf("%lld%lld", &op, &t); // 最后一次特殊处理，保证每一个都可以出去
        for (long long i = 1; i <= n; ++i)
        {
            if (good[i].ifwait == 1)
            {
                good[i].outtime = t + T;
                good[i].ifout = 1;
            }
            else
            {
                good[i].outtime = T - good[i].time + good[i].lasttime;
            }
        }
    }
    for (long long i = 1; i <= n; ++i)
    {
        printf("%lld ", good[i].outtime);
    }
    return 0;
}