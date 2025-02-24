#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char S1[105], S2[105];
int T, n, k;
long long a[255];
char getone(int n, int k)
{
    if (n == 1)
    {
        return S1[k - 1];
    }
    else if (n == 2)
    {
        return S2[k - 1];
    }
    else
    {
        if (k > a[n / 2])
        {
            return getone(n - 1, k - a[n / 2]);
        }
        else
        {
            return getone(n / 2, k);
        }
    }
}
int main()
{
    scanf("%s%s%d", S1, S2, &T);
    a[1] = strlen(S1);
    a[2] = strlen(S2);
    for (int i = 3; i <= 250; ++i)
    {
        a[i] = a[i / 2] + a[i - 1];
    }
    while (T--)
    {
        scanf("%d%d", &n, &k);
        printf("%c\n", getone(n, k));
    }
    return 0;
}