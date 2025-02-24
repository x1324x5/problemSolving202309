#include <cstdio>
#include <iostream>
using namespace std;
int T;
char a[4], b[4], c[4];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s%s", a, b, c);
        if (a[0] == a[1] && a[1] == a[2] && a[0] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[0] == a[1] && a[1] == a[2] && a[0] == '2')
        {
            printf("right hand win!\n");
        }
        else if (b[0] == b[1] && b[1] == b[2] && b[0] == '2')
        {
            printf("right hand win!\n");
        }
        else if (b[0] == b[1] && b[1] == b[2] && b[0] == '1')
        {
            printf("left hand win!\n");
        }
        else if (c[0] == c[1] && c[1] == c[2] && c[0] == '2')
        {
            printf("right hand win!\n");
        }
        else if (c[0] == c[1] && c[1] == c[2] && c[0] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[0] == b[0] && b[0] == c[0] && a[0] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[0] == b[0] && b[0] == c[0] && a[0] == '2')
        {
            printf("right hand win!\n");
        }
        else if (a[1] == b[1] && b[1] == c[1] && a[1] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[1] == b[1] && b[1] == c[1] && a[1] == '2')
        {
            printf("right hand win!\n");
        }
        else if (a[2] == b[2] && b[2] == c[2] && a[2] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[2] == b[2] && b[2] == c[2] && a[2] == '2')
        {
            printf("right hand win!\n");
        }
        else if (a[0] == b[1] && b[1] == c[2] && a[0] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[0] == b[1] && b[1] == c[2] && a[0] == '2')
        {
            printf("right hand win!\n");
        }
        else if (a[2] == b[1] && b[1] == c[0] && a[2] == '1')
        {
            printf("left hand win!\n");
        }
        else if (a[2] == b[1] && b[1] == c[0] && a[2] == '2')
        {
            printf("right hand win!\n");
        }
        else
        {
            printf("tie!\n");
        }
    }
    return 0;
}