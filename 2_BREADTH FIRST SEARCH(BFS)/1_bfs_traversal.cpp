#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005]; //adjacency list : vector type er array
bool vis[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true; //source node ke visited kore dilam , true diye
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child : v[par]) //vector type er array er proti ti index e ache vector...vector er proti ta index er value gula ekta ekta kore ber hbe
        {
            if (vis[child] == false) //vector theke 1ta 1ta value ber hobe , and check korbo oi value visited kina , visited nahole queue push krbo
            {
                q.push(child);
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
        //adjacency list e push korbo
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src; //source : graph er suru jekhan theke hbe
    cin >> src;
    memset(vis, false, sizeof(vis)); //suru tei visited array ti initalize kortesi false diye.
    bfs(src);
    return 0;
}