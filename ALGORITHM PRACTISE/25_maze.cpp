
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
int si, sj, di, dj;
 
char mz[N][N];
bool vis[N][N];
pair<int, int> path[N][N];
 
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m && mz[i][j] != '#';
}
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
 
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
     
        for (auto x : d)
        {
            int ci = a + x.first;
            int cj = b + x.second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {x.first, x.second};
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
            cin >> mz[i][j];
            if (mz[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (mz[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // vsit[i][j]=false;
            path[i][j]={-1,-1};
 
        }
    }
    bfs(si, sj);
    if (!vis[di][dj])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mz[i][j] ;
            }
            cout << endl;
        }
    }

    else
    {
        pair<int, int> dest = {di, dj};
        vector<pair<int, int>> v;
        while (dest.first != si || dest.second != sj)
        {
            v.push_back(path[dest.first][dest.second]);
            dest.first =  dest.first - v.back().first;
            dest.second = dest.second - v.back().second;
            if(mz[dest.first][dest.second]!='R'){
                mz[dest.first][dest.second] = 'X';
            }
        }
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                cout << mz[i][j];
            }

            cout << endl;
        }
    }
 
    return 0;
}