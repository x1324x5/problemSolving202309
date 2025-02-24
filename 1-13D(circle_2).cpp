#include <cstdio>
#pragma GCC optimize(3)
using namespace std;
const int N = 1e6 + 5;
int d[N], n, circle[N] = {0}, ans = 0, ifvis[N] = {0}; // circlr[i]=1 means point i has been in one circle
int main()
{
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n && circle[i] == 0; ++i)
    {
        int vis[N] = {0}; // vis[i]=1 means point i has been visited
        int next = i;
        int flag = 0;
        while (vis[next] == 0)
        {
            if (ifvis[next] == 1)
            {
                flag = 1;
                break;
            }
            ifvis[next] = 1;
            vis[next] = 1;

            next = d[next];

        } // easy to know that whatever point to be a starter, it will get into a circle
        if (flag == 1)
        {
            continue;
        }
        if (next == d[next])
        {
            circle[next] = 1;
        } // a circle with only one point
        else
        {
            int round = next;
            circle[round] = 1;
            next = d[next];
            while (next != round)
            {
                circle[next] = 1;
                next = d[next];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (circle[i] == 1)
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}