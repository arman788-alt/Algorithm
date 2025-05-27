#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<pair<int, int>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second > b.second)
            return true;

        else
            return false;
    }
};

void dij(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();

        int node = par.first;
        int cost = par.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9 + 9;
    }

    int src;
    cin >> src;
    dij(src);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        if (dis[m] <= n)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}

Can Go?
Explanation: 
আপনাকে N সংখ্যক নোড ও e সংখ্যক এজ দেওয়া থাকবে। সাথে প্রতি এজ এর সোর্স ডেস্টিনেশন ও কস্ট দেওয়া থাকবে। নোডগুলো ১ থেকে N অব্দি থাকবে। আপনাকে একটা সোর্স দেওয়া থাকবে। তারপর টেস্টকেইস এ T সংখ্যক ডেস্টনেশন আর DW কস্ট বলা থাকবে। আপনাকে বলতে হবে আপনি S থেকে D তে DW কিংবা তারও কম কস্ট এ যেতে পারবেন কিনা।

Hints
প্রথমে নোড আর এজ সংখ্যা ইনপুট নিবেন। তারপর গ্রাফটি ইনপুট নিবেন মোডিউলে যেভাবে দেখানো হয়েছে সেভাবে। তারপর সোর্স ইনপুট নিবেন। তারপর সোর্স বরাবর Dijkstra ফাংশন চালাবেন। এরপর টেস্টকেইস ইনপুট নিয়ে D আর DW ইনপুট নিবেন। তারপর ডিস্টেন্স এ্যারেতে D এর ডিস্টেন্স DW এর সমান বা ছোট কিনা চেক করবেন। যদি হয় তাহলে yes প্রিন্ট করবেন আর নাহলে no প্রিন্ট করবেন।




