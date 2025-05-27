#include <iostream>
#include <cstring> 
using namespace std;

int d[1001][1001]; 
int knapsack(int n, int items[], int weight[], int w)
{

    if (n == 0 || w == 0)
        return 0;

    if (d[n][w] != -1)
        return d[n][w];


    if (weight[n - 1] <= w)
    {
        int option1 = items[n - 1] + knapsack(n - 1, items, weight, w - weight[n - 1]);
        int option2 = knapsack(n - 1, items, weight, w);
        
        return d[n][w] = max(option1, option2);
    }
    else
    {
        return d[n][w] = knapsack(n - 1, items, weight, w);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int items[n];
        int weight[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> items[i];
        }

        memset(d, -1, sizeof(d));

        cout << knapsack(n, items, weight, w) << endl;
    }

    return 0;
}
