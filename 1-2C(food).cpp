#include <iostream>
using namespace std;
int main()
{
    int ce, br, ap, yo;
    cin >> ce >> br >> ap >> yo;
    if (ce == 1 || br == 1)
    {
        if (ap == 1 && yo == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}