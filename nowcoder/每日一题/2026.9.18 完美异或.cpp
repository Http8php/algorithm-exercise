/*
思路：一种构造方案是前n-1个数放1，异或和为pre，最后放n ^ pre
最后异或和为n，符合题目要求

单组时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << 1 << " ";
        pre ^= 1;
    }
    cout << (n ^ pre) << '\n';
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