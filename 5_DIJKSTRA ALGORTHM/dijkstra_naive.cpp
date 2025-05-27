#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];
void dijkstra(int src)
{
    queue<pair<int, int>> q; // pair er first value hocche soucre, 2nd value oy source e jawar bortoman cost.
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;

        // for(int i = 0; i<v[node].size(); i++)
        // {
        //    pair<int, int> child = v[node][i];
        //}
        for (pair<int, int> child : v[node])
       
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;     // c mean cost
        v[a].push_back({b, c}); // a theke b te jawar cost hocche c
        v[b].push_back({a, c}); // b theke a te jawar cost hocche c
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << "-> " << dis[i] << endl;
    }
    return 0;
}

//complexity hisab
//proti ta node N-1 ber update hoite pare. N-1 ke N bola jay.
//Complexity: (V*E) V mean node