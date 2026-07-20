/*
知识点：贪心

思路：要尽可能拆成偶数，只需遇到偶数就把之前的数塞进答案里
从小到大输出，由于数字以字符串形式存在，先比长度，再比字典序

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(string a, string b)
{
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}
void solve()
{
    string s, cur;
    cin >> s;
    vector<string>ans;
    for (char c : s)
    {
        cur += c;
        if ((c - '0') % 2 == 0) 
        {
            ans.push_back(cur);
            cur = "";
        }
    }
    if (cur != "") ans.push_back(cur);
    sort(ans.begin(), ans.end(), cmp);
    for (string x : ans)
    {
        cout << x << '\n';
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