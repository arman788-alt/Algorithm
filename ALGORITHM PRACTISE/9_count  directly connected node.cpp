#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int node;
    cin >> node;
    int cnt = 0;

    for (int child : v[node])
    {
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}
//Question: You will be given an undirected graph as input. Then you will be given a node N. 
//You need to print the number of nodes that are directly connected to the node N.

Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
2

Sample Output
2




