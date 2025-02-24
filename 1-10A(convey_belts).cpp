#include <cstdio>
#include <queue>
using namespace std;
int out = 0;
int n = 0, m = 0, Time = 0;
struct obj
{
    int pos = 0, inTime = 0, move = 0;
};
obj good[1005];
struct belts
{
    queue<int> work, wait;
    int weight = 0;
};
belts belt[11];
int T[11] = {}, W[11] = {}, t[1005] = {}, w[1005] = {};
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &T[i], &W[i]);
    }
    for (int j = 1; j <= m; ++j)
    {
        scanf("%d%d", &t[j], &w[j]);
    }
    int dotime = 0;
    while (out < m)
    {
        for (int i = 1; i <= m; ++i)
        {
            if (good[i].pos == n && good[i].move == 1) // 最后一个传送带里面结束之后表示有东西完成了
            {

                good[i].inTime += dotime;
                if (good[i].inTime == T[good[i].pos])
                {
                    out++;
                    belt[good[i].pos].weight -= w[i];
                    belt[good[i].pos].work.pop();
                    good[i].pos = n + 1;
                }
            }
            else if (good[i].move == 0 && good[i].pos >= 1 && good[i].pos <= n) // 中间某个等待队列里面，如果前面没有等待的货物就可以判断是否应该继续运作
            {

                if (belt[good[i].pos].wait.front() == i)
                {

                    if (belt[good[i].pos].weight + w[i] <= W[good[i].pos])
                    {
                        good[i].move = 1;
                        belt[good[i].pos].weight += w[i];
                        good[i].inTime = 0;
                        belt[good[i].pos].wait.pop();
                        belt[good[i].pos].work.push(i);
                    }
                    if (belt[good[i].pos].work.size() == 0 && w[i] > W[good[i].pos])
                    {
                        printf("invalid\n");
                        return 0;
                    }
                }
            }
            else if (good[i].move == 1 && good[i].pos >= 1 && good[i].pos <= n)
            {

                good[i].inTime += dotime;
                if (good[i].inTime == T[good[i].pos])
                {
                    good[i].move = 0;
                    belt[good[i].pos].weight -= w[i];
                    belt[good[i].pos].work.pop();
                    good[i].pos++;
                    belt[good[i].pos].wait.push(i);
                    if (belt[good[i].pos].wait.front() == i)
                    {
                        if (belt[good[i].pos].weight + w[i] <= W[good[i].pos])
                        {
                            good[i].move = 1;
                            belt[good[i].pos].weight += w[i];
                            good[i].inTime = 0;
                            belt[good[i].pos].wait.pop();
                            belt[good[i].pos].work.push(i);
                        }
                        if (belt[good[i].pos].work.size() == 0 && w[i] > W[good[i].pos])
                        {
                            printf("invalid\n");
                            return 0;
                        }
                    }
                }
            }
            else if (good[i].pos == 0)
            {

                if (Time < t[i])
                {
                }
                else
                {
                    good[i].pos = 1;
                    good[i].move = 0;
                    belt[good[i].pos].wait.push(i);
                    if (belt[good[i].pos].wait.front() == i)
                    {
                        if (belt[good[i].pos].weight + w[i] <= W[good[i].pos])
                        {
                            good[i].move = 1;
                            belt[good[i].pos].weight += w[i];
                            good[i].inTime = 0;
                            belt[good[i].pos].wait.pop();
                            belt[good[i].pos].work.push(i);
                        }
                    }
                }
            }
        }

        dotime = 2e6;
        for (int i = 1; i <= m; ++i)
        {
            if (good[i].pos <= n && good[i].pos >= 1 && good[i].move == 1)
            {
                int temp = T[good[i].pos] - good[i].inTime;
                if (temp < dotime)
                {
                    dotime = temp;
                }
            }
            else if (good[i].pos == 0)
            {
                int temp = t[i] - Time;
                if (temp < dotime)
                {
                    dotime = temp;
                }
            }
        }
        Time += dotime;
    }
    Time -= 2e6;
    printf("%d\n", Time);
    return 0;
}