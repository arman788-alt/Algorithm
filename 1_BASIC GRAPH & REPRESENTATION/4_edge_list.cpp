#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    for (pair<int, int> p : v) //chaile auto p use kora  jay....auto automatically bujbe p kon dhoroner datatype datatype she onujay rakhee
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}