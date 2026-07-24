/*
知识点：字符串哈希

思路：按题意模拟

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<string, int>mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!mp.count(s))
        {
            cout << "OK\n";
            mp[s]++;
        }
        else
        {
            int num = mp[s];
            mp[s]++;
            s += to_string(num);
            cout << s << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}