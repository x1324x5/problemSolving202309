#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
int pos = 0;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int opt;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (pos > 0)
            {
                pos--;
            }
            else
            {
                printf("invalid option 1\n");
            }
            break;
        case 2:
            if (pos < num.size())
            {
                pos++;
            }
            else
            {
                printf("invalid option 2\n");
            }
            break;
        case 3:
            int x;
            scanf("%d", &x);
            num.insert(num.begin() + pos, x);
            pos++;
            break;
        case 4:
            if (pos > 0)
            {
                num.erase(num.begin() + pos - 1);
                pos--;
            }
            else
            {
                printf("invalid option 4\n");
            }
            break;
        case 5:
            if (!num.empty() && pos > 0)
            {
                printf("%d\n", num[pos - 1]);
            }
            else
            {
                printf("invalid option 5\n");
            }
            break;
        case 6:
            printf("%d\n", pos);
            break;
        }
    }

    return 0;
}
