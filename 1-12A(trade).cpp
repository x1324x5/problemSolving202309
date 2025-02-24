#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct price
{
    int sell = 0, buy = 0;
};
double p, pricez = 0, median = 0;
char opt;
long long q;
int n;
vector<double> prices;
vector<long long> sell_sums(prices.size()), buy_sums(prices.size());
long long sell_sum = 0, buy_sum = 0;
vector<int> indedex;
long long max_q = 0;
unordered_map<double, price> orders;
vector<double> max_vals;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %c\n", &opt);
        scanf("%d%lf", &q, &p);
        if (opt == 'S')
        {
            orders[p].sell += q;
        }
        else
        {
            orders[p].buy += q;
        }
    }
    for (const auto &kp : orders)
    {
        prices.push_back(kp.first);
    }
    sort(prices.begin(), prices.end());
    for (int i = 0; i < prices.size(); ++i)
    {
        if (i == 0)
        {
            sell_sums[i] = orders[prices[i]].sell;
            buy_sums[i] = orders[prices[i]].buy;
        }
        else
        {
            sell_sums[i] = sell_sums[i - 1] + orders[prices[i]].sell;
            buy_sums[i] = buy_sums[i - 1] + orders[prices[i]].buy;
        }
    }
    for (int i = 0; i < prices.size(); ++i)
    {
        pricez = prices[i];
        q = min(sell_sums[i], buy_sums.back() - buy_sums[i] + orders[pricez].buy);
        if (q > max_q)
        {
            max_q = q;
            indedex.clear();
            indedex.push_back(i);
        }
        else if (q == max_q)
        {
            indedex.push_back(i);
        }
    }
    for (int idx : indedex)
    {
        max_vals.push_back(prices[idx]);
    }
    if ((int)((max_vals[0] + max_vals[max_vals.size() - 1]) * 100) & 1 == 1)
    {
        median = ((max_vals[0] + max_vals[max_vals.size() - 1]) + 0.01) / 2;
    }
    else
    {
        median = (max_vals[0] + max_vals[max_vals.size() - 1]) / 2;
    }
    printf("%.2lf\n", median);
    return 0;
}
