#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum = sum + a[i];
        }

        if (sum % 2 == 0)
        {
            int total = sum / 2;
            bool d[n + 1][total + 1];
            d[0][0] = true;

            for (int i = 1; i <= total; i++)
            {

                d[0][i] = false;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= total; j++)
                {
                    if (a[i - 1] <= j)
                    {
                        d[i][j] = d[i - 1][j - a[i - 1]] || d[i - 1][j];
                    }
                    else
                    {
                        d[i][j] = d[i - 1][j];
                    }
                }
            }

            if (d[n][total])
                cout << "YES" << endl;

            else
                cout << "NO" << endl;
        }

        else
            cout << "NO" << endl;
    }

    return 0;
}