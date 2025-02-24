#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 5005;

struct Node
{
    int left, right; // 区间的左右边界
    char winner;     // 胜者
} tree[MAXN << 2];

char win(char a, char b)
{
    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R'))
    {
        return a;
    }
    return b;
}

void build(int root, int left, int right, char str[])
{
    tree[root].left = left;
    tree[root].right = right;
    if (left == right)
    {
        tree[root].winner = str[left - 1];
        return;
    }
    int mid = (left + right) >> 1;
    build(root << 1, left, mid, str);
    build(root << 1 | 1, mid + 1, right, str);
    tree[root].winner = win(tree[root << 1].winner, tree[root << 1 | 1].winner);
}

char query(int root, int left, int right)
{
    if (tree[root].left == left && tree[root].right == right)
    {
        return tree[root].winner;
    }
    int mid = (tree[root].left + tree[root].right) >> 1;
    if (right <= mid)
    {
        return query(root << 1, left, right);
    }
    else if (left > mid)
    {
        return query(root << 1 | 1, left, right);
    }
    else
    {
        return win(query(root << 1, left, mid), query(root << 1 | 1, mid + 1, right));
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);

    while (T--)
    {
        char a[MAXN];
        scanf("%s", a);
        int n = strlen(a);

        // 构建线段树
        build(1, 1, n, a);

        // 查询操作
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(1, 1, mid) == query(1, mid + 1, n))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        printf("%c\n", a[l - 1]);
    }

    return 0;
}
