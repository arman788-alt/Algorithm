#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int vis[1005];

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    bool paisi = false;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int parent = par.first;
        int level = par.second;

        if (parent == des)
        {
            cout << level << endl;
            paisi = true;
        }

        for (int child : v[parent])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }

    if (paisi == false)
    {
        cout << -1 << endl;
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

    int src;
    cin >> src;

    memset(vis, false, sizeof(vis));
    bfs(src, 4);

    return 0;
}