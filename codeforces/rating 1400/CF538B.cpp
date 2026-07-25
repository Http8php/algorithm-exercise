/*
知识点：贪心

思路：如果有十进制位数值>1，就把该位填成1，其余填成0

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>cnt(7);
    int cur = 0, x = n;
    while (x > 0)
    {
        cnt[cur++] = x % 10;
        x /= 10;
    }
    vector<string>ans;
    while (1)
    {
        int i = 6;
        while (i >= 0 && cnt[i] == 0) i--;
        if (i == -1) break;
        string s = "";
        for ( ; i >= 0; i--)
        {
            if (cnt[i])
            {
                s += '1';
                cnt[i]--;
            }
            else s += '0';
        }
        ans.push_back(s);
    }
    cout << ans.size() << '\n';
    for (string s : ans)
    {
        cout << s << " ";
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