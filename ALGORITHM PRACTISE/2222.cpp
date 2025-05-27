#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v;
        int sz  = v.size();

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            v.push_back(val);
        }
 
        long long first_value = 0;
        long long second_value = 0;

        long long f_value = INT_MIN;
        long long s_value= INT_MIN;
 
        vector<long long> arr;
        for (int i = 0; i < sz; i++)
        {
            if (v[i] > f_value)
            {
                s_value = f_value;
                second_value = first_value;
                f_value = v[i];
                first_value = i;
            }
            else if (v[i] > s_value and v[i] != f_value)
            {
                s_value = v[i];
                second_value = i;
            }
        }

        arr.push_back(first_value);
        arr.push_back(second_value);

        sort(arr.begin(), arr.end());
 
        cout << arr[0] << " " << arr[1] << endl;
    }
    return 0;
}