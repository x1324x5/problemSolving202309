#include <cstdio>
using namespace std;

struct point
{
    point *father;
    point *lson = NULL, *rson = NULL;
    int numb = 0;
} point1[1000005], point2[1000005];

int n;
bool left1[1000005], left2[1000005];
int dad1[1000005], dad2[1000005];

bool check(point *a1, point *a2)
{
    if ((a1 == NULL && a2 != NULL) || (a1 != NULL && a2 == NULL))
        return false;
    if (a1 == NULL && a2 == NULL)
        return true;
    bool leftSame = check(a1->lson, a2->lson);
    bool rightSame = check(a1->rson, a2->rson);
    return leftSame && rightSame;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        point1[i].numb = i;
        point2[i].numb = i;
    }
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &dad1[i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &left1[i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &dad2[i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &left2[i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (left1[i])
        {
            point1[i].father = &point1[dad1[i]];
            point1[dad1[i]].lson = &point1[i];
        }
        else
        {
            point1[i].father = &point1[dad1[i]];
            point1[dad1[i]].rson = &point1[i];
        }
        if (left2[i])
        {
            point2[i].father = &point2[dad2[i]];
            point2[dad2[i]].lson = &point2[i];
        }
        else
        {
            point2[i].father = &point2[dad2[i]];
            point2[dad2[i]].rson = &point2[i];
        }
    }

    if (check(&point1[1], &point2[1]))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
