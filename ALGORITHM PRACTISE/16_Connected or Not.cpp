#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> v[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int q;
    cin >> q;
   
    while (q--)
    {

        int src, des;
        cin >> src >> des;
        bool flag = false;

        for (int child : v[src])
        {
            if (child == des)
            {
                flag = true;
                break;
            }
        }
        if(src == des)
        flag = true;
        if(flag)
        cout << "YES"<< endl;
        else
        cout << "NO" << endl;
    }

    return 0;
}Connected or Not
Explanation: 

আপনাকে একটি ডাইরেক্টেড গ্রাফ ইনপুট হিসেবে দেওয়া হবে। তারপর আপনাকে A এবং B দুইটা নোড ইনপুট হিসেবে দেওয়া হবে। আপনাকে বের করতে হবে A থেকে B তে অন্য কোনো নোড ইউজ না করে যাওয়া সম্ভব কিনা।


Hints
মোডিউলে যেভাবে ডাইরেক্টেড গ্রাফ ইনপুট নেওয়া দেখানো হয়েছে সেভাবে ইনপুট নিন। এবার কুয়েরি ইনপুট নিয়ে সেটার লুপ চালান ও সোর্স আর ডেস্টিনেশন ইনপুট নিন। এরপর এডজেসেন্সি লিস্ট এ দেখুন সোর্স এর লিস্ট এ ডেস্টিনেশন আছে কিনা অথবা সোর্স আর ডেস্টিনেশন সেইম নোড কিনা। যদি হয় তাহলে YES প্রিন্ট করুন আর নাহলে NO প্রিন্ট করুন।




