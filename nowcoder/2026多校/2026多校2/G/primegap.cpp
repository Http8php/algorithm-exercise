/*
这段代码计算了1e7内的素数距离，最大为154
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 10;
bool vis[N];
vector<int>p;
void init()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                vis[j] = true;
            }
        }
    }
    // 先筛再收集，不然只有sqrt(N)内的素数
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) p.push_back(i);
    }
}
void solve()
{
    init();
    int sz = p.size();
    cout << sz << '\n'; // 664579
    int mx = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        mx = max(mx, p[i+1] - p[i]);
    }
    cout << mx; // 154
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