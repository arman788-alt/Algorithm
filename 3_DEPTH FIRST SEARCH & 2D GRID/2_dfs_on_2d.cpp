#include <bits/stdc++.h>
using namespace std;
char a[20][20];
bool vis[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)//i hocche row, j hocche column matrix er ij mile matrix er 1taa cell bujay.
        return false;
    return true;
}
void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)//1ta node/cell er bam e dane e upore nichee jabe, 1ta node er dame,dane,opore,niche 4ta child.
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false) //ekhane age cell valid kinaa check hbe, cell invalid hole, age visited kina check korte gele error khabo.
                                                           //node er child e ashar age check korbo..node er child valid kinaa and tarpor check korbo oy child visited kinaa.
        {
            dfs(ci, cj);
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
    int si, sj;//si And sj matrix er cell, je cell sourcing hisebe start hbe.
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
    return 0;
}