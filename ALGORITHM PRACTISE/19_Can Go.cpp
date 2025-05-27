#include <bits/stdc++.h>
using namespace std;

int n, m;
int ai, aj, bi, bj;

char v[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    else
        return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + p[i].first;
        int cj = sj + p[i].second;

        if (valid(ci, cj) == true && vis[ci][cj] == false && (v[ci][cj] == '.' || v[ci][cj] == 'B') )
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
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (v[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));

    dfs(ai, aj);

    if (vis[bi][bj] == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


Can Go?

Explanation:  
আপনাকে N x M সাইজের 2D ম্যাট্রিক্স দেয়া হল যা একটি বিল্ডিংয়ের একটি মানচিত্র উপস্থাপন করে। প্রতিটি সেলে দেয়াল অথবা ফ্লোর অথবা রুম থাকবে। আপনাকে A এবং B দুইটি রুম দেয়া হবে। 
আপনার থেকে বলতে হবে A রুম থেকে B রুমে ফ্লোর দিয়ে যাওয়া যাবে কিনা। ফ্লোর সেলে আপনি উপরে, নিচে, ডানে, বামে চলাচল করতে পারবেন। কিন্তু আপনি দেয়াল অতিক্রম করতে পারবেন না। 
ইনপুটেঃ
#  হল দেয়াল
. হল ফ্লোর
A এবং B হল রুম




Hints
প্রথমে 2D ম্যাট্রিক্সটিকে ইনপুট নিবেন। 
এরপর A রুমের index (ai, aj) বের রাখবেন এবং B রুমের index(bi, bj) বের করে রাখবেন। 
A রুমের index দিয়ে BFS অথবা DFS চালাবেন।  BFS অথবা DFS চালানোর পর চেক করবেন B রুমের index (bi, bj) কি ভিজিটেড কিনা,
 যদি ভিজিটেড হয় তাহলে বলা যায় A রুম থেকে B নোডে যাওয়া যায়, অন্যথায় যাওয়া সম্ভব নয়। 

