/*
思路：首先要看到一定包含一个1
偶回文：BOB可以一直让串是回文，直到还剩两个0，等ALICE填完后翻转，比ALICE少填两次
奇回文：ALICE第一步填在中间就可以变成偶回文，只要1的数量>1

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
    if (n == 1)
    {
        cout << "BOB\n";
        return;
    }
    int cnt = 0;
    for (char c : s)
    {
        if (c == '0') cnt++;
    }
    cout << (cnt % 2 == 0 || cnt == 1 ? "BOB\n" : "ALICE\n");
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