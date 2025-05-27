#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
vector<int> v1;
int vis[1005];

void bfs(int src, int l)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        if (level == l)
        v1.push_back(par);

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src = 0;
    int l;
    cin >> l;
    memset(vis, false, sizeof(vis));

    bfs(src, l);

    sort(v1.begin(), v1.end(), greater<int>()); // Corrected sorting

    for (int val : v1)
    {
        cout << val << " ";
    }

    return 0;
}

//Question: You will be given an undirected graph which will be connected as input. 
//Then you will be given a level L. You need to print the node values at level L in descending order. 
//The source will be 0 always.

//sample inpput
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
1

//sample output
3 2 1