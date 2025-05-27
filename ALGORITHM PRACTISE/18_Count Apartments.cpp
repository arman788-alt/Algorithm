#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[1000][1000];
char a[1000][1000];
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= N || j < 0 || j >= M)
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

        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int com = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vis[i][j] == false && a[i][j] == '.')
            {
                dfs(i, j);
                com++;
            }
        }
    }

    cout << com << endl;

    return 0;
}

//You are given an N*M sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. 
//The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. 
//You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).


Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 0

3




Count Apartments
Explanation: 
আপনাকে N x M সাইজের 2D ম্যাট্রিক্স দেয়া হল যা একটি বিল্ডিংয়ের একটি মানচিত্র উপস্থাপন করে। প্রতিটি সেলে দেয়াল রুম থাকবে। কানেক্টেড সব রুম কে এপার্টমেন্ট বলা হয়।  আপনার একটি বিল্ডিংয়ে কতটি এপার্টমেন্ট আছে সেইটি বের করতে হব। । সেলে আপনি উপরে, নিচে, ডানে, বামে চলাচল করতে পারবেন। কিন্তু আপনি দেয়াল অতিক্রম করতে পারবেন না। 
ইনপুটেঃ
#  হল দেয়াল
. হল রুম

Hints
প্রথমে 2D ম্যাট্রিক্সটিকে ইনপুট নিবেন। 
এরপর 2D ম্যাট্রিক্স এর যেই ইনডেক্সে (.) পাওয়া যাবে এবং ইনডেক্সটি আনভিজিটেড হলে সেই ইনডেক্সটি দিয়ে DFS অথবা BFS চালবেন এইভাবে যতবার DFS অথবা BFS চালাতে পারবেন সেইটি কাউন্ট করবেন এবং সেই কাউন্টটিকেই আউটপুট হিসেবে দেখাতে হবে। 







