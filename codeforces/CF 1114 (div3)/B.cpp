/*
标签：贪心

思路：最优情况是有形如 ...aba...，把b删除可以增加两段
次优情况是有形如 ...abc...，把b删除增加一段
其他情况无论删哪个字母都无影响

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int>v;
    int cur = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i+1]) cur++;
        else
        {
            v.push_back(cur);
            cur = 1;
        }
    }
    v.push_back(cur);
    int sz = v.size();
    bool has1 = false, has2 = false;
    for (int i = 1; i < n - 1; i++)
    {
        // 最优
        if (s[i-1] == s[i+1] && s[i] != s[i-1]) has1 = true;
        // 次优
        if (s[i-1] != s[i+1] && s[i] != s[i-1] && s[i] != s[i+1]) has2 = true;
    }
    if (has1) cout << sz - has1 * 2 << '\n';
    else if (has2) cout << sz - has2 << '\n';
    else cout << sz << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}