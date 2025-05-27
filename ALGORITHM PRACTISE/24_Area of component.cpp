#include <bits/stdc++.h>
using namespace std;

const int N = 1005; 

vector<string> v;
int vis[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool Valid(int x, int y, int n, int m)
 {
    return (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.');
}

int bfs(int si, int sj, int n, int m)
 {
    queue<pair<int, int>> q;
    q.push({si, sj});

    vis[si][sj] = 1;
    int area = 0;

    while (!q.empty())
     {
        pair<int,int> par = q.front();
        q.pop();
        area++;

        for (auto c : d) 
        {
            int nx = par.first + c.first;
            int ny = par.second + c.second;

            if (Valid(nx, ny, n, m) && !vis[nx][ny])
             {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    return area;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    int min_Area = INT_MAX;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
         {
            if (v[i][j] == '.' && !vis[i][j])
             {
                min_Area = min(min_Area, bfs(i, j, n, m));
            }
        }
    }

    if (min_Area == INT_MAX)
        cout << "-1" << endl;
    else
        cout << min_Area << endl;

    return 0;
}