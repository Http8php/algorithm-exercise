/*
知识点：贪心

思路：这题需要注意力，观察到出布一定更优，且无论放在什么位置
对手 布 我方 布(0) 石头(-1) 对手 石头 我方 布 (1) 石头 (0) 出布净赚1分
一共可以出 floor(n / 2) 个布，再与对手布的数量抵消，就是最终答案

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int cp = 0, ans = 0;
    for (char c : s)
    {
        if (c == 'p') cp++;
    }
    ans = n / 2 - cp;
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