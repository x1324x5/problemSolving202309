#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, q, a[1000005] = {}, t[1000005] = {}, x = 0;
int decide(int i) // 对于结果x的每一个二进制位，去找一个0或1使得最终结果对应的这一个位子上尽量为1
{
    int goal = 1;                     // 最初想让结果的第i位为1，每一次要做某个运算，会使得目标改变
    for (int j = n; j > 0; --j)       // 对于每个第i位，只用考虑每一个数字二进制的第i位，进而可以决定输入的数字应该是多少
    {                                 // 倒过来找，每次改变或者不改变目标，因为对于某些情况可以直接随意确定0和1，这样更快
        int temp = ((t[j] >> i) & 1); // 找到t[j]的第i位是多少，0或1，移位之后再和1作AND操作，直接得到最后一位
        if (goal == 1)                // 如果此时目标还是1
        {
            switch (a[j]) // 看操作是哪一个
            {
            case (1):          // OR操作下，要想让目标是1，就会让某个数来和temp去操作，接下来看什么数可以满足目标为1的操作
                if (temp == 1) // 如果OR对应的操作数是1，那随便找个数都可以使得结果为1，那x二进制对应的这一位上随便是几都可以
                {
                    return 0; // 就取个0
                }
                break; // 如果操作数是0，那这时候如果是1来和他操作，就能得到目标，因此目标改为1，也就是不变
            case (2):
                if (temp == 0) // AND操作下，如果是0，那无论是0还是1都只能得到0，随便就行
                {
                    return 0;
                }
                break; // 如果是1，那就要1来和他操作，目标改为1，也就是不变
            case (3):
                if (temp == 1) // 类似的，如果是1来操作，就需要0，目标改为0，否则不变
                {
                    goal = 0;
                }
                break;
            }
        }
        else
        {
            switch (a[j])
            {
            case (1):
                if (temp == 1) // 和上面类似，现在要和1来进行OR操作，目标是得到0，怎么样都不可能
                {
                    return 0;
                }
                break;
            case (2):
                if (temp == 0) // 和上面类似，现在要和0来进行AND操作，目标是得到0，怎么样都可以
                {
                    return 0;
                }
                break;
            case (3):
                if (temp == 1) // 和上面类似，现在要和1来进行XOR操作，目标是得到0，目标改为1
                {
                    goal = 1;
                }
            }
        }
    }
    return goal;
}
int main()
{
    scanf("%d%d", &n, &q);
    if (q == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            char op[3];
            scanf("%s", &op);
            scanf("%d", &t[i]);
            if (strcmp(op, "OR") == 0) // 将输入的运算符用123来代表
            {
                a[i] = 1;
            }
            else if (strcmp(op, "AND") == 0)
            {
                a[i] = 2;
            }
            else
            {
                a[i] = 3;
            }
        }
        for (int i = 0; i < q; ++i)
        {
            x += decide(i) * pow(2, i); // 输出结果对应的十进制数
        }
        printf("%d", x);
        return 0;
    }
}