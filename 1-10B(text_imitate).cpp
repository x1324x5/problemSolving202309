#include <cstdio>
#include <stack>
using namespace std;
stack<int> number; // 记录数字
int pos = 0;       // 记录光标的位置，代表光标前面有几个数字
int n = 0, opt = 0;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case (1):
        {
            if (pos == 0)
            {
                printf("invalid option 1\n");
            }
            else
            {
                pos--; // 光标左移
            }
            break;
        }
        case (2):
        {
            if (pos == number.size())
            {
                printf("invalid option 2\n");
            }
            else
            {
                pos++; // 光标右移
            }
            break;
        }
        case (3):
        {
            int x = 0;
            scanf("%d", &x);
            pos++;
            number.push(x); // 数字压进去，光标右移
            break;
        }
        case (4):
        {
            if (pos == 0)
            {
                printf("invalid option 4\n");
            }
            else
            {
                stack<int> temp;
                while (number.size() > pos)
                {
                    int tem = number.top();
                    temp.push(tem);
                    number.pop();
                } // 把这个栈里面的数丢到temp里面
                number.pop();
                pos--; // 删掉光标前面那个数，位置减一
                while (!temp.empty())
                {
                    int tem = temp.top();
                    number.push(tem);
                    temp.pop();
                } // 再把temp里面的是丢回来
            }
            break;
        }
        case (5):
        {
            if (pos == 0)
            {
                printf("invalid option 5\n");
            }
            else
            {
                stack<int> temp = number;
                int tem = pos; // 复制一份栈和光标位置，把光标后面的数全丢了，找到前面那个数输出
                while (temp.size() > tem)
                {
                    temp.pop();
                }
                printf("%d\n", temp.top());
            }
            break;
        }
        case (6):
        {
            printf("%d\n", pos); // 输出位置
            break;
        }
        }
    }
    return 0;
}