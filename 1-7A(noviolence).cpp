#include <cstdio>
using namespace std;
int s0, n, D, a[5005], b[5005], sta, c[5005], d[5005]; // sta代表当前的状态,c代表每一天的吃和不吃相差的大小,d代表当天有没有吃
int main()
{
    scanf("%d%d%d", &s0, &D, &n);
    sta = s0 - D; // 之后只用比较sta和0的大小关系
    if (sta < 0)
    {
        printf("-1\n"); // 一来就死了
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        c[i] = a[i] + b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    { // 对于每一天，如果当天不吃东西就要死了，就在当天及前面的天里面找出没有吃食物的c[i]最大的那一天
        while (sta - b[i] < 0)
        {
            int temp = 0, index = 0; // temp用于存放最大值，index代表那一天的标号
            for (int j = 1; j <= i; ++j)
            {
                if (d[j] == 0) // 那一天的东西是没有吃的才检索
                {
                    if (c[j] >= temp) // 某天更大就替换
                    {
                        temp = c[j];
                        index = j; // 记录最大的指标
                    }
                }
            }
            d[index] = 1; // 最大的这一天的食物吃掉
            if (index != i)
            {
                sta = sta + c[index]; // 吃掉的不是第i个，就要回复a+b
            }
            else
            {
                sta += a[index]; // 吃掉的刚好是第i个，就只增加a[i]
                i++;
            }
        } // 这个时候活过来了
        if (d[i] == 0)
        {
            sta -= b[i]; // 刚刚没有吃i就能度过这一天，就状态减去b[i]
        }
    }
    for (int i = 1; i <= n; ++i) // 找出没有吃食物的天数
    {
        if (d[i] == 0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}