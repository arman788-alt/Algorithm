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
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            v.push_back(val);
        }
 
         long long mn1 = INT_MIN;
        long long mn2 = INT_MIN;
        
        long long first_value = 0;
        long long second_value = 0;
        
        
 
        vector<long long> arr;
        int size = v.size();
        for (int i = 0; i < size; i++)
        {
            if (v[i] > mn1)
            {
                mn2 = mn1;
                second_value = first_value;
                
                mn1 = v[i];
                first_value = i;  
            }
            
             if (v[i] > mn2 and v[i] != mn1)
            {
                second_value = i;
                mn2 = v[i];   
            }
        }
        
        
        arr.push_back(first_value);
        arr.push_back(second_value);
        sort(arr.begin(),arr.end());
 
        cout <<arr[0]<<" "<<arr[1]<<endl;
    }
    
    return 0;
}