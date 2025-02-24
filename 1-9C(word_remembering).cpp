#include <cstdio>
#include <queue>
using namespace std;
int n, m;
struct word
{
    int enterTime = 0;
    bool inq = 0;
    int allTime = 0;
    bool exist = 0;
    int id = 0;
};
queue<word> Q;
word a[1000005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int wordNow = 0;
        scanf("%d", &wordNow);
        if (Q.size() < m)
        {
            if (a[wordNow].inq == 0)
            {

                a[wordNow].enterTime = i;
                a[wordNow].inq = 1;
                a[wordNow].exist = 1;
                a[wordNow].id = wordNow;
                Q.push(a[wordNow]);
            }
        }
        else
        {
            if (a[wordNow].inq == 0)
            {
                a[wordNow].enterTime = i;
                a[wordNow].inq = 1;
                a[wordNow].exist = 1;
                a[wordNow].id = wordNow;
                Q.push(a[wordNow]);
                int temp = Q.front().id;
                Q.pop();
                a[temp].allTime += i - a[temp].enterTime;
                a[temp].inq = 0;
            }
        }
    }
    while (!Q.empty())
    {
        int temp = Q.front().id;
        Q.pop();
        a[temp].allTime += n + 1 - a[temp].enterTime;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].exist == 1)
        {
            printf("%d %d\n", i, a[i].allTime);
        }
    }
    return 0;
}