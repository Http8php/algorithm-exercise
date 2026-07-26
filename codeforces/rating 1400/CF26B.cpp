/*
知识点：贪心

思路：一个合法的序列为左括号在左边，右括号在右边
遍历字符串，每当有右括号，就与左括号(如果有)配对

时间：O(L) L为字符串长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int ans = 0, cl = 0;
    for (char c : s)
    {
        if (c == '(') cl++;
        else
        {
            if (cl > 0)
            {
                cl--;
                ans += 2;
            }
        }
    }
    cout << ans;
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