#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false  && a[ci][cj] == '.') 
                                                           
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
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);


    int di,dj;
    cin >> di >> dj;
    if(vis[di][dj] == true)
    cout << "YES" << endl;

    else
    cout << "NO" << endl;
    return 0;
}

Same Component
Explanation: 
আপনাকে একটি 2D গ্রিড দেওয়া হবে। যেখানে ‘.’ আর ‘-’ থাকবে। ‘.’ দিয়ে বোঝায় আপনি সেই সেল এ যেতে পারবেন আর ‘-’ দিয়ে বোঝায় আপনি সেই সেল এ যেতে পারবেন না।
 আপনাকে সোর্স আর ডেস্টিনেশন বলে দেওয়া হবে। আপনাকে বলতে হবে সোর্স থেকে ডেস্টিনেশনে যাওয়া পসিবল কিনা?
Hints
প্রথমে গ্রিড এর সারি আর কলাম সংখ্যা ইনপুট নিবেন। তারপর 2D গ্রিড ইনপুট নিবেন। 
তারপর সোর্স আর ডেস্টিনেশন ইনপুট নিয়ে মোডিউলে যেভাবে দেখানো হয়েছে সেভাবে সোর্স এর উপর DFS on 2D গ্রিড বা BFS অন 2D  গ্রিড চালাবেন। তারপর দেখবেন ডেস্টিনেশন ভিজিটেড কিনা। 
যদি হয় তাহলে YES আর নাহলে NO প্রিন্ট করবেন।

//input
5 4
..-.
---.
..-.
--..
....
0 1
3 2

//output
not



