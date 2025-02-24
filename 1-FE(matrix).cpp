#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 919260817;
const int MAXN = 100;              // 假设矩阵的最大维度
const int MAXTREENODES = 4 * MAXN; // 线段树节点的最大数量

int n, k, q, l, r;

int mul(int a, int b)
{
    return int((a * 1LL * b) % mod);
}

int add(int a, int b)
{
    return (a + b) >= mod ? (a + b - mod) : (a + b);
}

struct Matrix
{
    int mat[MAXN][MAXN];
    int n;

    Matrix(int size = 0) : n(size)
    {
        // 构造函数中不再进行初始化
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix product(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                long long sum = 0;
                for (int k = 0; k < n; ++k)
                {
                    sum = add(sum, mul(mat[i][k], other.mat[k][j]));
                }
                product.mat[i][j] = sum;
            }
        }
        return product;
    }
};

Matrix tree[MAXTREENODES];
Matrix mats[MAXN];
Matrix stand; // k 维单位矩阵
void bui(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = mats[start];
    }
    else
    {
        int mid = (start + end) / 2;
        bui(2 * node, start, mid);
        bui(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] * tree[2 * node + 1];
    }
}
Matrix que(int node, int start, int end)
{
    if (r < start || end < l)
    {
        return stand; // 直接返回单位矩阵
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    Matrix p1 = stand, p2 = stand; // 初始化为单位矩阵
    if (l <= mid)
    {
        p1 = que(2 * node, start, mid);
    }
    if (r > mid)
    {
        p2 = que(2 * node + 1, mid + 1, end);
    }
    return p1 * p2;
}

int main()
{
    scanf("%d %d %d", &n, &k, &q);
    stand = Matrix(k); // 初始化 k 维单位矩阵
    for (int i = 0; i < k; ++i)
    {
        stand.mat[i][i] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            for (int m = 0; m < k; ++m)
            {
                scanf("%d", &mats[i].mat[j][m]);
            }
        }
    }

    bui(1, 0, n - 1);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        l--;
        r--;
        Matrix result = que(1, 0, n - 1);
        for (int j = 0; j < k; ++j)
        {
            for (int m = 0; m < k; ++m)
            {
                printf("%d ", result.mat[j][m]);
            }
            printf("\n");
        }
    }
    return 0;
}