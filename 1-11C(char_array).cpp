#include <cstdio>
using namespace std;
int n = 0, a = 0;

int main()
{
    scanf("%d", &n);
    int last = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            if (last != 0)
            {
                cnt++;
            }
        }
        last = a;
    }
    if (a != 0)
    {
        printf("invalid string\n");
    }
    else
    {
        printf("%d", cnt);
    }
    return 0;
}