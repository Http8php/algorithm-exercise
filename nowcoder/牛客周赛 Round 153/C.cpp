/*
思路：与两个值交换的原理一样，每次可以操作3次交换两个值
就算最坏情况，也只有 n/2*3 次交换，小于2*n

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s, t = " " + t;
    // 提前找到需要交换的地方
    vector<int>pos10, pos01;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && t[i] == '0') pos10.push_back(i);
        if (s[i] == '0' && t[i] == '1') pos01.push_back(i);
    }
    cout << 3 * pos10.size() << '\n';
    int cur = 0;
    for (int x : pos10)
    {
        cout << x << '\n';
        cout << pos01[cur++] << '\n';
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