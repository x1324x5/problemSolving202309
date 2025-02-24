#include <cstring>
#include <cstdio>
using namespace std;
int n = 0, Q = 0, k = 0;
char s[105] = {}, t[105] = {};
long long fib[40] = {};
char find(int n, int k)
{
    if (n == 1)
    {
        return s[k - 1];
    }
    else if (n == 2)
    {
        return t[k - 1];
    }
    else
    {
        if (k <= fib[n - 2])
        {
            return find(n - 2, k);
        }
        else
        {
            return find(n - 1, k - fib[n - 2]);
        }
    }
}
int main()
{

    scanf("%s%s%d", s, t, &Q);
    int sl = strlen(s), tl = strlen(t);
    fib[1] = sl;
    fib[2] = tl;
    for (int i = 3; i <= 35; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while (Q--)
    {
        scanf("%d%d", &n, &k);
        int cnt = 1;
        while (cnt <= 10)
        {

            if (find(n, k + cnt - 1) != '\0')
            {
                printf("%c", find(n, k + cnt - 1));
            }
            else
            {
                break;
            }
            cnt++;
        }
        printf("\n");
    }
    return 0;
}