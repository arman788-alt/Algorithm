#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, e;
    cin >> n >> e;
    long long int adj[n+1][n+1];
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            adj[i][j] = 1e18;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < adj[a][b])
            adj[a][b] = c;
    }
    for (int k = 0; k <=n; k++)
    {
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <=n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dest;
        cin >> src >> dest;
        if (adj[src][dest] == 1e18)
            cout << "-1" << endl;

        else
            cout << adj[src][dest] << endl;
    }

    return 0;
}

Shortest Distance
Explanation: 
আপনাকে একটি গ্রাফের নোড N এবং edges E দেয়া হবে। Edges এর জন্য A, B এবং W দেয়া হবে, এইখানে A নোডের সাথে B নোডের edges আছে বুঝিয়েছে এবং এদের weight হচ্ছে W. 

এরপর আপনাকে কিছু query দেয়া হবে। প্রতিটি query তে আপনাকে X এবং Y দেয়া হবে, এইখানে X হচ্ছে source এবং Y হচ্ছে destination।  আপনার থেকে X নোড থেকে Y নোডে যেতে  minimum cost বের করতে হবে। যদি X থেকে Y নোডে যাওয়া সম্ভব না হলে তখন - 1 প্রিন্ট করতে হবে। 

দ্রষ্টব্য: এক নোড থেকে অন্য নোডে একাধিক edges থাকতে পারে।

Hints
এই প্রব্লেমটি আমরা Floyd Warshall algorithm দিয়ে করবো। 
প্রথমে N এবং E ইনপুট নিব। এরপর একটি 2D অ্যারে নিব যেইখানে মডিউলে দেখানো উপায়ে infinity (1e18) assign করবো। 
এরপর edges গুলোকে ইনপুট নিব। 
Edge ইনপুট নেয়া সময় খেয়াল রাখতে হবে যে, এক নোড থেকে অন্য নোডে একাধিক edges থাকতে পারে। যদি এক নোড থেকে অন্য নোডে একাধিক edge থাকে তখন সেইগুলোকে থেকে কম cost টিকে নিব। 
এরপর মডিউলে দেখানো Floyd Warshall algorithm চালিয়ে দিব। 


এরপর query ইনপুট নিব। প্রতিটি query তে পাওয়া source এবং destination এর cost টি প্রিন্ট করবো। যদি source এবং destination এর cost infinity পাওয়া যায় তাহলে -1 প্রিন্ট করবো , অন্যথায় cost প্রিন্ট করে দিব। 

