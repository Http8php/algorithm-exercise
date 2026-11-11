/*
思路：设 cnt=x-1，二进制位 (a0a1...am)2
a=cnt   (a0 a1 a2 ... )2
b=cnt/2 (   a0 a1 ... )2
mid=a ^ b (a0 a0 ^ a1 a1 ^ a2 ... )2
翻转mid (am ^ a{m-1} ... a0 ^ a1 a0)2
mid % 2^h = z 即mid的低h位等于z，高位任意
而低h位由于有a0，cnt的高h位pre能唯一确定，其他k-h位从全0到全1
cnt∈[pre*2^{k-h},pre*2^{k-h}+(2^{k-h}-1)]
x=cnt+1，与[l,r]求交集即可

时间：O(qh)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int k, q;
    cin >> k >> q;
    while (q--)
    {
        ll l, r, h, z;
        cin >> l >> r >> h >> z;
        // cur记录前缀异或
        ll pre = 0, cur = 0;
        for (int i = 0; i < h; i++)
        {
            cur ^= (z >> i) & 1;
            pre = (pre << 1) | cur;
        }
        ll base = 1ll << (k - h);
        ll L = pre * base + 1, R = (pre + 1) * base;
        ll ans = min(r, R) - max(l, L) + 1;
        cout << max(0ll, ans) << '\n';
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