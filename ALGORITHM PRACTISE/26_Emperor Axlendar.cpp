
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5 + 5;
int p[N];
int group_size[N];

void dsu(int n)
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (p[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(p[node]);
    p[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        p[leader2] = leader1;
        group_size[leader1] = group_size[leader1] + group_size[leader2];
    }
    else
    {
        p[leader1] = leader2;
        group_size[leader2] = group_size[leader2] + group_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu(n);

    vector<pair<int, pair<int, int>>> edge;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edge.push_back({c, {u, v}});
    }

    sort(edge.begin(), edge.end());

    ll mincost = 0;
    int Edge = 0;
    for (auto x : edge)
    {
        int u = x.second.first;
        int v = x.second.second;
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if (leaderU == leaderV)
        {
            Edge++;
            continue;
        }
        else
        {
            dsu_union_by_size(u, v);
            mincost = mincost + x.first;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == -1)
        {
            count++;
        }
    }
    if (count > 1)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << Edge << " " << mincost << endl;
    }

    return 0;
}
