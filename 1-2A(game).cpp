#include <iostream>
#pragma GCC optimize(2)
using namespace std;
int mol(int index, int n)
{
    if (index >= n)
    {
        return index - n;
    }
    else
    {
        return index;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    int a[10003] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int all = n, index = 0;
    bool inCircle[10003] = {};
    inCircle[0] = true;
    while (all > 2)
    {
        int count = 0;
        int dead = index;
        while (count < a[dead])
        {
            index = mol(index + 1, n);
            if (!inCircle[index])
            {
                count++;
            }
        }
        inCircle[index] = true;
        all--;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!inCircle[i])
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}