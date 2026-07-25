/*
知识点：构造

思路：考虑化简式子
当a_{2i-1}>a_2i，即从1~2n排列，左边抵消，对答案贡献为0
发现只要让第一组的差为+k，右边就会等于2k

时间：O(2 * n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << k + 1 << " ";
    for (int i = 1; i <= n * 2; i++)
    {
        if (i != k + 1) cout << i << " ";
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