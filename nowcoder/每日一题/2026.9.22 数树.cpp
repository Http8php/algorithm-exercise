/*
思路：发现满二叉树能导出最多的满二叉树，每层从左往右填充是最优的
所以满二叉树要满足的条件是根存在并且最深处最右侧的节点存在
从根出发，一直往右孩子走：x -> 2x+1 -> 2(2x+1)+1=4x+3 -> 8x+7
于是有规律，当深度为h时，编号为x*2^h+(2^h-1)=(x+1)2^h-1
编号必须存在，所以(x+1)2^h-1<=n -> x<=floor((n+1)/2^h)-1
h从0开始，解出的x就是所有深度为h的树数量，2^h增长很快，循环次数不会很多

单组时间：O(logn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    ll n, ans = 0;
    cin >> n;
    n++;
    while (n)
    {
        ans = (ans + n - 1) % mod;
        n >>= 1;
    }
    cout << ans << '\n';
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