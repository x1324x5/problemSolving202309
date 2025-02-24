#include <cstdio>
using namespace std;
long long s0, k, D, n;
long long food[10005];
int main()
{
    scanf("%ld%ld%ld%ld", &s0, &k, &D, &n); // 输入数据
    for (int i = 1; i <= n; ++i)
    {
        scanf("%ld", &food[i]); // 输入食物的权值
    }
    int ans = n, j = 1, i = 1; // ans代表剩下的可以不吃食物的天数，j代表即将吃的食物的编号，i代表天数
    while (i <= n)
    {
        if (s0 - (n + 1 - i) * k >= D) // 在第i天的时候，如果状态很好，好到剩下的天数都不用吃东西就能活下来，就可以输出ans
        {
            printf("%d\n", ans);
            break;
        }
        else // 状态没有那么好
        {
            s0 = s0 + food[j] - k; // 吃掉当前的食物，并且度过这一天
            j++;                   // 食物变成下一个
            i++;                   // 天数加一
            ans--;                 // 能不吃食物的天数减少
            if (s0 < D)            // 状态很不好，吃了食物都活不下来就退出
            {
                printf("-1\n");
                break;
            } // 进入下一天
        }
    }
    return 0;
}