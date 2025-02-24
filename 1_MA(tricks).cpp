#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n, k, d, i = 0;
string num;
vector<long long> con;
long long cnt[1000];
long long nums = 0;
long long change(string num)
{
    long long ans = 0;
    int len = num.length();
    for (int j = 0; j < len; ++j)
    {
        ans = ans * d + (num[j] - '0');
    }
    return ans;
}
string backs(int num)
{
    string result = "";
    while (num > 0)
    {
        int remainder = num % d;
        result = to_string(remainder) + result;
        num /= d;
    }
    return result;
}
int main()
{
    scanf("%d%d%d", &n, &k, &d);
    while (n--)
    {
        cin >> num;
        nums = change(num);
        cnt[nums]++;
    }
    while (cnt[i] == k || cnt[i] == 0)
    {

        i++;
    }
    cout << backs(i);
    return 0;
}