#include <bits/stdc++.h>
using namespace std;

//2taa graph alada alada thakle, orthat ektar sathe arekta connected na thakle 2taa graph ke aladaa vabe component bujay.
//amra chaile 2ta graph eksathe traverse korte pari.
//ei chara componenet er logic diye 2ta graph er sum etc bair korte pari..



const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];

//int sum = 0;
void dfs(int src)
{
    cout << src << endl;
    // sum = sum + src; //total sum of the component/ graphs
    vis[src] = true;
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
    memset(vis, false, sizeof(vis));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            c++;
        }
    }
    cout << "component - " << c << endl;
    return 0;
}