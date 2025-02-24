#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ConveyorBelt
{
    int T;
    int W;
};

struct Item
{
    int index;
    int arrivalTime;
    int weight;

    bool operator<(const Item &other) const
    {
        // Items with earlier arrival time have higher priority
        if (arrivalTime != other.arrivalTime)
            return arrivalTime > other.arrivalTime;

        // Items with smaller index have higher priority
        return index > other.index;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ConveyorBelt> belts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> belts[i].T >> belts[i].W;
    }

    priority_queue<Item> waitingQueue;
    vector<Item> items(m);
    for (int i = 0; i < m; i++)
    {
        items[i].index = i;
        cin >> items[i].arrivalTime >> items[i].weight;
    }

    int currentTime = 0;
    vector<int> completionTimes(m, -1);

    for (int i = 0; i < n; i++)
    {
        int remainingCapacity = belts[i].W;

        // Process items in the waiting queue
        while (!waitingQueue.empty() && waitingQueue.top().arrivalTime <= currentTime)
        {
            Item item = waitingQueue.top();
            waitingQueue.pop();

            if (item.weight <= remainingCapacity)
            {
                // Item can be loaded onto the current conveyor belt
                remainingCapacity -= item.weight;
                completionTimes[item.index] = currentTime + belts[i].T;
            }
            else
            {
                // Item goes to the next waiting queue
                waitingQueue.push(item);
                break;
            }
        }

        // Load new items onto the current conveyor belt
        while (!items.empty() && items.back().arrivalTime <= currentTime)
        {
            Item item = items.back();
            items.pop_back();

            if (item.weight <= remainingCapacity)
            {
                // Item can be loaded onto the current conveyor belt
                remainingCapacity -= item.weight;
                completionTimes[item.index] = currentTime + belts[i].T;
            }
            else
            {
                // Item goes to the next waiting queue
                waitingQueue.push(item);
            }
        }

        currentTime += belts[i].T;
    }

    if (waitingQueue.empty())
    {
        // All items have been processed
        int maxCompletionTime = *max_element(completionTimes.begin(), completionTimes.end());
        cout << maxCompletionTime << endl;
    }
    else
    {
        // There are still items in the waiting queue
        cout << "invalid" << endl;
    }

    return 0;
}