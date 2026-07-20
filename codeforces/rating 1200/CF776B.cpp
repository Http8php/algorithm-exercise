/*
知识点：素数筛

思路：只有合数有小于自身的素因子，所以所有合数都是一个颜色
素数只有本身整个素因子，所以所有素数都是一个颜色
要特判n<3，此时只有素数，只有一种颜色

时间：O(NloglogN)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
bool vis[N];
void init()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                if (!vis[j]) vis[j] = true;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    if (n <= 2) cout << 1 << '\n';
    else cout << 2 << '\n';
    for (int i = 2; i <= n + 1; i++)
    {
        if (vis[i]) cout << 2 << " ";
        else cout << 1 << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}