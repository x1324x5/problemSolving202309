#include <cstdio>
using namespace std;
int start[1005];
int N, M, K;
struct qiZi
{
    int up = 0;
    int down = 0;
};
qiZi q[1055];
int findpos(int a)
{
    while (q[a].down <= M)
    {
        a = q[a].down;
    }
    return q[a].down;
}
int findtop(int a)
{
    while (q[a].up != 0)
    {
        a = q[a].up;
    }
    return a;
}
int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= M; i++)
    {

        int pos = 0;
        scanf("%d", &pos);
        if (q[pos + M].up == 0)
        {
            q[pos + M].up = i;
            q[i].down = pos + M;
        }
        else
        {
            q[q[pos + M].up].down = i;
            q[i].up = q[pos + M].up;
            q[i].down = pos + M;
            q[pos + M].up = i;
        }
    }
    // printf("%d", q[1].down - 3);
    for (int i = 1; i <= K; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int pos = findpos(a);
        q[q[a].down].up = 0;
        q[a].down = 0;
        int top = findtop(pos + b);
        q[top].up = a;
        q[a].down = top;
    }
    for (int i = 1; i <= M; i++)
    {
        printf("%d ", findpos(i) - M);
    }
    return 0;
}