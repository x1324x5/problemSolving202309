#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int x[5005] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] > x[j])
            {
                count++;
            }
        }
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
    printf("%d", count);
    return 0;
}