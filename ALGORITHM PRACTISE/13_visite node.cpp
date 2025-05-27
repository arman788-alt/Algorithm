#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int cnt = 0;

void dfs(int src)
{
    vis[src] = true;
    cnt++;

    for (int child : v[src])
    {
        if (vis[child] == false)
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int node;
    cin >> node;
    memset(vis, false, sizeof(vis));
    dfs(node);
    cout << cnt << endl;

    return 0;
}

//Question: You will be given an undirected graph as input.
// Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.

Sample Input
6 5

0 1
0 2
0 3
2 3
4 5

//N
2

Sample Output
4



