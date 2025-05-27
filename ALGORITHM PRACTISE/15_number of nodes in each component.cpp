#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int cnt = 0;

vector<int> component; // component

void dfs(int src)
{
    vis[src] = true;
    cnt++;

    for (int child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
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

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {   cnt = 0;
            dfs(i);
            component.push_back(cnt);
        }
    }

    for(int i = 0; i<component.size(); i++)
    {
        cout << component[i] << endl;
    }

    return 0;
}

/
/Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.
Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
Sample Output
2 4


