#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

char win(char a, char b)
{
    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R'))
    {
        return a;
    }
    return b;
}

int main()
{
    int T;
    scanf("%d\n", &T);

    while (T--)
    {
        string a;
        cin >> a;
        int index = a.length();
        while (index > 1)
        {
            for (int i = 0; i < index - 1; ++i)
            {
                a[i] = win(a[i], a[i + 1]);
            }
            --index;
        }
        printf("%c\n", a[0]);
    }

    return 0;
}
