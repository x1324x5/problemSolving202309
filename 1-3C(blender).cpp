#include <iostream>
#include <cstdio>
using namespace std;
void change(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}
void print(int arr[][101], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n = 0, m = 0, K = 0;
    cin >> n >> m >> K;
    int arr[101][101] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int time = 0;
    for (int k = 1; k <= K; k++)
    {
        int l = 0, a = 0, b = 0;
        cin >> l;
        if (l == 3)
        {
            int alter[101][101] = {};
            time += 1;
            if (time % 2 == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        alter[i][j] = arr[i][j];
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        arr[j][n - i - 1] = alter[i][j];
                    }
                }
                print(arr, m, n);
            }
            else
            {
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        alter[i][j] = arr[i][j];
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        arr[j][m - i - 1] = alter[i][j];
                    }
                }
                print(arr, n, m);
            }
        }
        else if (l == 1)
        {
            cin >> a >> b;
            if (time % 2 == 0)
            {
                if (a > n || b > n || a <= 0 || b <= 0)
                {
                    printf("Invalid arguments!\n");
                }
                else
                {
                    for (int p = 0; p < m; p++)
                    {
                        change(arr[a - 1][p], arr[b - 1][p]);
                    }
                    print(arr, n, m);
                }
            }
            else
            {
                if (a > m || b > m || a <= 0 || b <= 0)
                {
                    printf("Invalid arguments!\n");
                }
                else
                {
                    for (int p = 0; p < n; p++)
                    {
                        change(arr[a - 1][p], arr[b - 1][p]);
                    }
                    print(arr, m, n);
                }
            }
        }
        else if (l == 2)
        {
            cin >> a >> b;
            if (time % 2 == 0)
            {
                if (a > m || b > m || a <= 0 || b <= 0)
                {
                    printf("Invalid arguments!\n");
                }
                else
                {
                    for (int p = 0; p < n; p++)
                    {
                        change(arr[p][a - 1], arr[p][b - 1]);
                    }
                    print(arr, n, m);
                }
            }
            else
            {
                if (a > n || b > n || a <= 0 || b <= 0)
                {
                    printf("Invalid arguments!\n");
                }
                else
                {
                    for (int p = 0; p < m; p++)
                    {
                        change(arr[p][a - 1], arr[p][b - 1]);
                    }
                    print(arr, m, n);
                }
            }
        }
    }
    return 0;
}