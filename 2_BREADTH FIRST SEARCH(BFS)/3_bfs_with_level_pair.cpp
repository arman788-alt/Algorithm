#include <bits/stdc++.h>
using namespace std;


vector<int> v[1005];
bool vis[1005];
void bfs(int src, int des)
{   
    queue<pair<int, int>> q;//queue er type hobe pair type --2ta data rakhte parbe, ekta node er jonno, arekta level er jonno.
    q.push({src, 0});
    vis[src] = true;
    bool paisi = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;
        // cout << par << endl;
        if (par == des) //par er value jodi des(9) er soman hoy , tahole bujbo oitay amr destination,,,and tar er level print korbo
        {
            cout << level << endl;
            paisi = true; 
        }
        for (int child : v[par])
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
    bfs(src, 9); //9 hocche amader desitanation, source (mane level 0) theke 9 er level koto ta bair korbo.
    return 0;
}