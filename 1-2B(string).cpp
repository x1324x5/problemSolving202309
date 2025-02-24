#include <iostream>
#include <string>
using namespace std;
int main()
{
    string T = "";
    cin >> T;
    string S = "";
    int start = 0;
    int len = T.length();
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(T[i]))
        {
            string temp = T.substr(start, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) - start);
            start = i + 1;
            int tem = T[i] - 48;
            for (int j = 0; j < tem; ++j)
            {
                S += temp;
            }
        }
    }
    cout << S << endl;
    return 0;
}