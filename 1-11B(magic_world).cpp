#include <cstdio>
#define N 505
using namespace std;
struct node
{
    int x, y;
    node *left = NULL, *right = NULL, *up = NULL, *down = NULL;
};
node all[N][N];
int n = 0, T = 0, px = 1, py = 1;
char con;
int set(int i, int j)
{
    if (1 < i && i < n && 1 < j && j < n)
    {
        all[i][j].left = &all[i - 1][j];
        all[i][j].right = &all[i + 1][j];
        all[i][j].up = &all[i][j + 1];
        all[i][j].down = &all[i][j - 1];
    }
    else if (i == n && j == n)
    {
        all[i][j].left = &all[i - 1][j];
        all[i][j].down = &all[i][j - 1];
    }
    else if (i == n && j > 1 && j < n)
    {
        all[i][j].left = &all[i - 1][j];
        all[i][j].up = &all[i][j + 1];
        all[i][j].down = &all[i][j - 1];
    }
    else if (i == n && j == 1)
    {
        all[i][j].left = &all[i - 1][j];
        all[i][j].up = &all[i][j + 1];
    }
    else if (1 < i && i < n && j == 1)
    {
        all[i][j].left = &all[i - 1][j];
        all[i][j].right = &all[i + 1][j];
        all[i][j].up = &all[i][j + 1];
    }
    else if (i == 1 && j == 1)
    {
        all[i][j].right = &all[i + 1][j];
        all[i][j].up = &all[i][j + 1];
    }
    else if (i == 1 && 1 < j && j < n)
    {
        all[i][j].right = &all[i + 1][j];
        all[i][j].down = &all[i][j - 1];
        all[i][j].up = &all[i][j + 1];
    }
    else if (i == 1 && j == n)
    {
        all[i][j].right = &all[i + 1][j];
        all[i][j].down = &all[i][j - 1];
    }
    else if (1 < i && i < n && j == n)
    {
        all[i][j].right = &all[i + 1][j];
        all[i][j].left = &all[i - 1][j];
        all[i][j].down = &all[i][j - 1];
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            all[i][j].x = i;
            all[i][j].y = j;
            set(i, j);
        }
    }
    if (n == 1)
    {
        while (T--)
        {
            scanf(" %c", &con);
            if (con == 'P')
            {
                printf("(1,1)\n");
            }
        }
    }
    else
    {
        while (T--)
        {
            scanf(" %c", &con);
            switch (con)
            {
            case ('W'):
                if (all[px][py].up != NULL)
                {
                    py = all[px][py].up->y;
                }
                break;
            case ('A'):
                if (all[px][py].left != NULL)
                {
                    px = all[px][py].left->x;
                }
                break;
            case ('S'):
                if (all[px][py].down != NULL)
                {
                    py = all[px][py].down->y;
                }
                break;
            case ('D'):
                if (all[px][py].right != NULL)
                {
                    px = all[px][py].right->x;
                }
                break;
            case ('B'):
                if (all[px][py].left != NULL)
                {
                    all[px][py].left->right = all[px][py].right;
                }
                if (all[px][py].right != NULL)
                {
                    all[px][py].right->left = all[px][py].left;
                }
                if (all[px][py].up != NULL)
                {
                    all[px][py].up->down = all[px][py].down;
                }
                if (all[px][py].down != NULL)
                {
                    all[px][py].down->up = all[px][py].up;
                }

                break;
            case ('P'):
                printf("(%d,%d)\n", px, py);
                break;
            }
        }
    }
    return 0;
}