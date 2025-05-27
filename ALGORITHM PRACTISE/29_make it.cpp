#include <bits/stdc++.h>
using namespace std;

int d[100000];
int n;
int Make_It(int v)
{
    if (n == v)
        return 1;

     if (n < v)
        return 0;

     if (d[v] != -1)
        return d[v];

    int d1 = Make_It(v + 3);
    int d2 = Make_It(v * 2);

    return d[v] = d1 || d2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        memset(d, -1, sizeof(d));

        if (Make_It(1))
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}