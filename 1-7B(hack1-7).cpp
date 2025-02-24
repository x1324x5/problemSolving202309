#include <cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    printf("3 2 %d\n", n);
    printf("%d ", 10 * n);
    for (int i = 1; i <= n - 1; i++)
    {
        printf("1 ");
    }
    printf("\n");
    printf("0 ");
    for (int i = 1; i <= n - 1; i++)
    {
        printf("5 ");
    }
}