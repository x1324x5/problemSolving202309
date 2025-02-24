#include <cstdio>
using namespace std;
int check(int a[], int j, int b[]) // 检查在这个数组中前面有没有和第j个位置相同的数字，有就返回第一个相同数字的位置
{
    for (int i = 1; i < j; i++)
    {
        if (a[i] == a[j] && b[i] == b[j])
        {
            return i;
            break;
        }
    }
    return 0;
}
int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int inter = n / d;
    int m = n;
    n = n - inter * d;
    int arr[100000] = {}; // 保存计算结果的每一位
    int brr[100000] = {}; // 保存每一次计算的余数
    n *= 10;
    for (int i = 1; i < 100000; i++) // 获得两个数组
    {
        arr[i] = int(n / d);
        int z = n - arr[i] * d;
        n = 10 * z;
        brr[i] = z;
    }
    int end = 0, start = 0;
    for (int i = 1; i <= d + 1; i++) // 利用计算结果和余数都相同找出第一次重复的位置，进而找出循环节结束的位置
    {
        if (check(arr, i, brr) != 0 && brr[i] == brr[check(arr, i, brr)])
        {
            end = i - 1;
            break;
        }
    }
    for (int j = 1; j <= end; j++) // 找出循环节开始的位置
    {
        if (arr[j] == arr[end + 1] && brr[j] == brr[end + 1])
        {
            start = j;
            break;
        }
    }
    if (end == start && arr[end] == 0) // 有限小数和整数的情况
    {
        printf("%d.", inter);
        if (inter * d == m) // 整数
        {
            printf("0");
        }
        else // 有限小数，
        {
            for (int i = 1; i < start; i++)
            {
                printf("%d", arr[i]);
            }
        }
    }
    else // 循环小数的情况
    {
        printf("%d.", inter);
        for (int i = 1; i < start; i++)
        {
            printf("%d", arr[i]);
        }
        printf("(");
        for (int i = start; i <= end; i++)
        {
            printf("%d", arr[i]);
        }
        printf(")");
    }
    return 0;
}