#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
const int N(1e7 + 3);
typedef unsigned uint;
uint c1, c2;
uint seed;
int cnt, _n, _q;
int qu[N];
int a[N], f[N];
int n, p, l, r;
void _magic()
{
    c1 ^= (c1 << 17);
    c1 ^= (c1 >> 5);
    c1 ^= (c1 << 19);
    c2 ^= (c2 << 13);
    c2 ^= (c2 >> 4);
    c2 ^= (c2 << 23);
    seed = (seed * seed + c1) % c2;
}
uint rnd()
{
    _magic();
    return (seed << 17) ^ (seed >> 5) ^ (seed << 23);
}
#define MAXVALUE 1000000000

#define MINLEN ((_n + 1) >> 1)

int _get()
{
    static int l = 1, r = _n;
    if (cnt == 0)
    {
        ++cnt;
        return _n;
    }
    else
    {
        if (cnt <= _n)
        {
            ++cnt;
            return rnd() % MAXVALUE;
        }
        if (cnt == _n + 1)
        {
            ++cnt;
            return _q;
        }
        else if (cnt <= _n + 1 + _q * 2)
        {
            if ((cnt - _n - 1) % 2 == 1)
            {
                ++cnt;
                int len = rnd() % (((MINLEN << 1 ^ (~(_n) & 1)) + 1) >> 1) + MINLEN;
                l = rnd() % (_n - len + 1) + 1;
                r = l + len - 1;
                return l;
            }
            else
            {
                ++cnt;
                return r;
            }
        }
    }
    return -1;
}
void init()
{
    /* Input the arguments (Do not modify!)*/
    scanf("%u%u%u%d%d", &c1, &c2, &seed, &_n, &_q);
}
int get()
{
    int ret = _get();
    if (ret == -1)
    {
        return -1;
    }
    return ret;
}
int main()
{
    init();
    n = get();
    p = (n + 1) / 2;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = get();
    }
    int q = get();
    int ans = 0;
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) // 以最大的2的幂次去分割n个数，用f[i]记录第i个数开头的这一串数字里面的最大值
    {
        while (hh <= tt and i - p >= qu[hh])
        {

            hh++;
        } // 处理队首
        while (hh <= tt and a[qu[tt]] <= a[i])
        {
            tt--;
        }             // 处理队尾
        qu[++tt] = i; // 队尾元素加入
        if (i >= p)
        {
            f[i - p + 1] = a[qu[hh]]; //
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        l = get();
        r = get();
        if (i == 1)
        {
            ans = std::max(f[l], f[r - p + 1]);
        }
        else
        {
            ans ^= std::max(f[l], f[r - p + 1]);
        }
    }
    printf("%d", ans);
    return 0;
}