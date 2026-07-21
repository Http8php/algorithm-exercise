/*
知识点：贪心

思路：假设第一次换了1，可以直接把1送到需要1的地方，此时手里是0，直接把0送到需要0的地方，以此类推
最后再交换一次第一次交换的地方，完成闭环，这样一定最优

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
    vector<int>pos10, pos01;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && t[i] == '0') pos10.push_back(i);
        if (s[i] == '0' && t[i] == '1') pos01.push_back(i);
    }
    if (pos10.size() == 0)
    {
        cout << 0;
        return;
    }
    int tot = pos10.size() + pos01.size() + 1;
    cout << tot << '\n';
    int i = 0, j = 0;
    for (int k = 1; k < tot; k++)
    {
        if (k % 2) cout << pos10[i++] << '\n';
        else cout << pos01[j++] << '\n';
    }
    cout << pos10[0] << '\n';
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