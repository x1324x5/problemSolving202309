#include <cstdio>
using namespace std;
int k, ar[11];
int num(int ar[])
{
    int num = 0;
    for (int i = 0; i <= 11; i++)
    {
        if (ar[i] != 0)
        {
            num += 1;
        }
    }
    return num;
}
void print(int n, int times, int bottom)
{
    if (n == 0)
    {
        if (times - 1 == k)
        {
            for (int q = 1; q < times; q++)
            {
                printf("%d ", ar[q]);
            }
            printf("\n");
        }
    }
    if (times <= k)
    {
        for (int j = bottom; j <= n; j++)
        {
            ar[times] = j;
            print(n - j, times + 1, j);
        }
    }
}
int main()
{
    int n;
    scanf("%d%d", &n, &k);
    if (n < k)
    {
        printf("Invalid");
    }
    else
    {
        print(n, 1, 1);
    }
}