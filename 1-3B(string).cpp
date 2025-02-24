#include <iostream>
using namespace std;
bool check(int len, int j, string subs, string t)
{
    for (int count = 0; count < len; count++)
    {
        if (subs[j + count] != t[count])
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    string s, t;
    cin >> s;
    int m, l, r;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r >> t;
        int len = t.length();
        string subs = s.substr(l - 1, r - l + 1);
        int times = 0;
        for (int j = 0; j <= r - l - len + 1; j++)
        {
            if (check(len, j, subs, t))
            {
                times += 1;
            }
        }
        cout << times << endl;
    }
    return 0;
}