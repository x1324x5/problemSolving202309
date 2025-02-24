#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct ConveyorBelt
{
    int T; // 物品通过传送带所需时间
    int W; // 传送带的最大承重
};

struct Item
{
    int t;
    int w;
    int pos;
};
struct waitingBelts
{
    queue<int> waiting;
};
waitingBelts wait[11];
queue<int> out;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<ConveyorBelt> belts(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &belts[i].T, &belts[i].W);
    }

    vector<Item> items(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &items[i].t, &items[i].w);
    }
    int time = items[0].t;
    
}