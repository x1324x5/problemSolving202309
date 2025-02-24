#include <cstdio>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int n;
string a;
stack<char> conduct;
vector<char> result;
int level(char a);
string address(string a)
{
    int l1 = a.length();
    a += '|';
    string done = "";
    for (int i = 1; i <= l1; ++i)
    {
        char last = a[i - 1];
        if (a[i] == '+' && (last < '0' || last > '9') && last != ')')
        {
            done += ':';
        }
        else if (a[i] == '-' && (last < '0' || last > '9') && last != ')')
        {
            done += ';';
        }
        else
        {
            done += a[i];
        }
    }
    return done;
}
vector<char> change(string done)
{
    int len = done.length();
    for (int i = 0; i < len; ++i)
    {
        if (done[i] >= '0' && done[i] <= '9')
        {
            result.push_back(done[i]);
        }
        else
        {
            if (conduct.empty())
            {
                conduct.push(a[i]);
            }
            else
            {
                int l = conduct.size();
                if (done[i] == '(')
                {
                    conduct.push(done[i]);
                }
                else if (done[i] == ')')
                {
                    while (conduct.top() != '(')
                    {
                        char temp;
                        temp = conduct.top();
                        result.push_back(temp);
                        conduct.pop();
                    }
                    conduct.pop();
                }
                else if (done[i] == '~' || done[i] == ':' || done[i] == ';')
                {
                    conduct.push(done[i]);
                }
                else
                {
                    while (!conduct.empty() && level(done[i]) <= level(conduct.top()))
                    {
                        char temp;
                        temp = conduct.top();
                        result.push_back(temp);
                        conduct.pop();
                    }
                    conduct.push(done[i]);
                }
            }
        }
        if (i == len - 1)
        {
            while (!conduct.empty())
            {
                char temp;
                temp = conduct.top();
                result.push_back(temp);
                conduct.pop();
            }
        }
        return result;
    }
}

int level(char a)
{
    switch (a)
    {
    case '(':
        return 1;
        break;
    case ')':
        return 1;
        break;
    case '^':
        return 2;
        break;
    case '&':
        return 2;
        break;
    case '~':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    case '%':
        return 3;
        break;
    case '+':
        return 4;
        break;
    case '-':
        return 4;
        break;
    case '>':
        return 5;
        break;
    case '<':
        return 5;
        break;
    }
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", &a);
        a = address(a);
        result = change(a);
        for (int i = 0; i < result.size(); ++i)
        {
            printf("%c", result[i]);
        }
    }
    return 0;
}