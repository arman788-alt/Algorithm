#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e18;
long long int dis[1005];

class Edge
{
public:
    long long int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = N;
    }

    long long int src;
    cin >> src;
    dis[src] = 0;
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int dest;
        cin >> dest;

        for (long long int i = 1; i <= n - 1; i++)
        {
            for (Edge ed : EdgeList)
            {
                long long int u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;
                if (dis[u] < N && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }
        bool cycle = false;
        for (Edge ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < N && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dis[dest] == N)
            cout << "Not Possible" << endl;

        else
            cout << dis[dest] << endl;
    }

    return 0;
}

Can Go Again?
Explanation:  

আপনাকে N সংখ্যক নোড ও e সংখ্যক এজ দেওয়া থাকবে। সাথে প্রতি এজ এর সোর্স ডেস্টিনেশন ও কস্ট দেওয়া থাকবে। নোডগুলো ১ থেকে N অব্দি থাকবে। আপনাকে একটা সোর্স দেওয়া থাকবে। তারপর টেস্টকেইস এ T সংখ্যক ডেসটিনেশন । আপনাকে বলতে হবে আপনি S থেকে D তে মিনিমাম কত কস্ট এ যেতে পারেন।

বি দ্রঃ যদি নেগেটিভ সাইকেল থাকে তাহলে Negative Cycle Detected প্রিন্ট করতে হবে।


Hints
প্রথঅমে নোড আর এজ সংখ্যা ইনপুট নিয়ে গ্রাফ এর এজলিস্ট ইনপুট নিবেন। তারপর ডিস্টেন্স এ্যারেতে ইনিশয়ালি 1e18 সেট করবেন। তারপর Bellman ford  এলগোরিদম চালাবেন। যদি নেগেটিভ সাইকেল পান তাহলে Negative Cycle Detected প্রিন্ট করবেন। তারপর টেস্টকেইস ইনপুট নিয়ে সেটার লুপ চালাবেন আর ডেস্টিনেশন ইনপুট নিবেন।  যদি সাইকেল না পান তাহলে চেক করবেন ডিস্টেন্স 1e18 এর ছোট কিনা। যদি হয় তাহলে ডিস্টেন্স প্রিন্ট করবেন আর নাহলে Not Possible প্রিন্ট করবেন।

