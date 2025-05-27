#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int level[1005];
int vis[1005];
bool paisi = false;

void bfs(int src, int des)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        if (par == des)
        {
            cout << level[par] << endl;
            paisi = true;
            return;
        }

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(src, des);
    }
    return 0;
}

// Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, 
//you will be given source S and destination D. You need to print the shortest distance between S and D.
// If there is no path from S to D, print -1.

Sample Input
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0

Sample Output
2
3
3
2
2
0



