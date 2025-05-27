#include <bits/stdc++.h>
using namespace std;
//adacecy list use : 1ta node er sathe kon kon node er connection ache , kom complexity or kom loop chaliye buja jay.
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n]; //vector type er array
    while (e--)
    {
        int a, b; // a, and b hocche node
        cin >> a >> b;
        //  // for undirected graph : a theke b te jawa jay, abr b theke a the jawa jay,, ubomokhii
        mat[a].push_back(b); // directed graph e only : mat[a][b] = 1
        mat[b].push_back(a);
    }
    
    for (int i = 0; i < mat[3].size(); i++)
    {
        cout << mat[3][i] << " "; //node 3 er sathe kon kon node er connection/edge ache buja jabe.
    }
    return 0;
}