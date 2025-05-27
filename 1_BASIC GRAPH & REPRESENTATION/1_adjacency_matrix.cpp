#include <bits/stdc++.h>
using namespace std;
// adjacency matrix use : kono 2ta node er maje edje/connection ache kinaa buja jay
// node er value hole always (0 to N-1 porjonto) 
//N - number of nodes,
//E - number of egde,
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b; // a, and b hocche node
        cin >> a >> b;
        // for undirected graph : a theke b te jawa jay, abr b theke a the jawa jay,, ubomokhii
        mat[a][b] = 1; // directed graph e only : mat[a][b] = 1
        mat[b][a] = 1;
    }
    if (mat[3][1] == 1) // mat[3][1] ei ceil e 1 thakle bujbo je 3 r 1 node moddhe edge dhara connected.
        cout << "connection ache";
    else
        cout << "connection nai";
    return 0;
}