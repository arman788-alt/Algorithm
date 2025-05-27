#include<bits/stdc++.h>
using namespace std;
int main()
{
 
 int n, e;
 cin >> n >> e;
 int mat[n][n];
 memset(mat, 0, sizeof(mat));

 while(e--)
 {
     int a, b;
     cin >> a >> b;
     mat[a][b] = 1;
     mat[b][a] = 1;
 }


 if(mat[0][2] == 1)
 cout << "Connection ache" << endl;


 else
 cout << "Connection nai" << endl;





    return 0;
}