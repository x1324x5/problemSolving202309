#include <cstdio>
#include <cmath>
using namespace std;
int n, k;
int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return f(floor(sqrt(n) / k)) + f(floor(sqrt(n) / (2 * k))) + floor(n / 2);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    printf("%d", f(n));
    return 0;
}