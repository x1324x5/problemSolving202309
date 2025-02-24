#include <cstdio>
#include <cstring>
#include <stack>
const int N = 919260817;
using namespace std;
stack<long long> s;
int main()
{
    char a[1000005];
    char ch, last = '=';
    long long x, y = 0;
    long long now = 0, ans = 0;
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        ch = a[i];
        if (ch >= '0' && ch <= '9')
        {
            now *= 10;
            now = now + ch - '0';
        }
        else if (ch == '+')
        {
            if ((last >= '0' && last <= '9'))
            {
                s.push(now);
                now = 0;
            }
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            x = s.top();
            s.pop();
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            y = s.top();
            s.pop();
            s.push((y % N + x % N + N) % N);
        }
        else if (ch == '-')
        {
            if ((last >= '0' && last <= '9'))
            {
                s.push(now);
                now = 0;
            }
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            x = s.top();
            s.pop();
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            y = s.top();
            s.pop();
            s.push((y % N - x % N + N) % N);
        }
        else if (ch == '*')
        {
            if ((last >= '0' && last <= '9'))
            {
                s.push(now);
                now = 0;
            }
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            x = s.top();
            s.pop();
            if (s.empty())
            {
                printf("INVALID!");
                return 0;
            }
            y = s.top();
            s.pop();
            s.push(((y % N) * (x % N)) % N);
        }
        else if (ch == '|')
        {
            s.push(now);
            now = 0;
        }
        last = ch;
    }
    if (s.empty())
    {
        printf("INVALID");
        return 0;
    }
    ans = (s.top() % N);
    s.pop();
    if (!s.empty())
    {
        printf("INVALID!");
        return 0;
    }
    printf("%ld", ans);
    return 0;
}