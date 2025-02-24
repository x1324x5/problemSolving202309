#include <cstdio>
#include <stack>
using namespace std;
stack<char> con;
int n, flag = 1;
char temp;
char a[1000005];
int check(char c)
{
    switch (c)
    {
    case ('('):
        con.push('(');
        break;
    case ('['):
        con.push('[');
        break;
    case ('{'):
        con.push('{');
        break;
    case (')'):
        if (con.empty())
        {
            flag = 0;
        }
        else
        {
            if (con.top() != '(')
            {
                flag = 0;
            }
            else
            {
                con.pop();
            }
        }
        break;
    case (']'):
        if (con.empty())
        {
            flag = 0;
        }
        else
        {
            if (con.top() != '[')
            {
                flag = 0;
            }
            else
            {
                con.pop();
            }
        }
        break;
    case ('}'):
        if (con.empty())
        {
            flag = 0;
        }
        else
        {
            if (con.top() != '{')
            {
                flag = 0;
            }
            else
            {
                con.pop();
            }
        }
        break;
    }
    return 0;
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", a);
        for (char c : a)
        {
            if (c != '\0')
            {
                check(c);
                if (flag == 0)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (!con.empty())
        {
            flag = 0;
        }
        if (flag == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        flag = 1;
        while (!con.empty())
        {
            con.pop();
        }
    }
    return 0;
}