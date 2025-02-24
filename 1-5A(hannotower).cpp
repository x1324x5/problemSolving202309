#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string A = "0", B = "0", C = "0";
int n = 0;
string block[15] = {};
void cut(string block[], int n, string temp[])
{
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = block[i + 1];
    }
}
void bring(int n, string block[], string A, string B, string C)
{
    if (n == 1)
    {
        printf("Move %s from %s to %s.\n", block[0].c_str(), A.c_str(), B.c_str());
    }
    else if (n == 2)
    {
        printf("Move %s from %s to %s.\n", block[1].c_str(), A.c_str(), C.c_str());
        printf("Move %s from %s to %s.\n", block[0].c_str(), A.c_str(), B.c_str());
        printf("Move %s from %s to %s.\n", block[1].c_str(), C.c_str(), B.c_str());
    }
    else
    {
        string temp[15] = {};
        cut(block, n, temp);
        bring(n - 1, temp, A, C, B);
        printf("Move %s from %s to %s.\n", block[0].c_str(), A.c_str(), B.c_str());
        bring(n - 1, temp, C, B, A);
    }
}
int main()
{
    cin >> n;
    getchar();
    getline(cin, A);
    getline(cin, B);
    getline(cin, C);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, block[i]);
    }
    bring(n, block, A, B, C);
    return 0;
}