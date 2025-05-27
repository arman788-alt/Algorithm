#include <bits/stdc++.h>
using namespace std;
char a[20][20];
bool vis[20][20];
int dis[20][20];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    else
        return true;
}

void bfs(int si, int sj)
{
    queue < pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        cout << a << " " << b << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = a + p[i].first;
            int cj = b + p[i].second;

            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    return 0;
}