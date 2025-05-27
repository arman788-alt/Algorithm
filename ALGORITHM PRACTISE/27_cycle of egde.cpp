#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int p[N];
int grp_size[N];

void dsu_intilization(int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = -1;
        grp_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (p[node] == -1)
        return node;

    int leader = dsu_find(p[node]);
    p[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{

    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if (grp_size[leader1] > grp_size[leader2])
    {
        p[leader2] = leader1;
        grp_size[leader2] = grp_size[leader2] + grp_size[leader1];
    }
    else
    {
        p[leader1] = leader2;
        grp_size[leader2] = grp_size[leader2] + grp_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int count = 0;

    dsu_intilization(n);

        while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);

        if (leader1 == leader2)
            count++;

        else
            dsu_union_by_size(a, b);
    }

    cout << count << endl;

    return 0;
}


Problem Statement

You will be given an undirected graph where there will be N nodes and E edges. You need to tell the number of edges that can create a cycle in the graph.

Note: Duplicate edges as input can not be possible. The value of nodes are 1 from N to .

Input Format

First line will contain N and E.
Next  lines will contain A and B which means there is a edge between A and B .
Constraints

Output Format

Output the number of edges that can create a cycle.
Sample Input 0

5 7
1 2
2 3
3 4
4 5
4 1
2 4
5 3
Sample Output 0

3
Sample Input 1

3 3
1 2
2 3
1 3
Sample Output 1

1