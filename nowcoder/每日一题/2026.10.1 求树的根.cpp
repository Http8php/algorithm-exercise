/*
思路：每条边都会提供一个出度和入度，记录所有点的出度和入度
根入度为0，叶子出度为0，分别输出

时间：O(xlogx) x为叶子节点数量
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>in(n + 1), out(n + 1);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        in[v]++, out[u]++;
    }
    int r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            r = i;
            break;
        }
    }
    set<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if (out[i] == 0) ans.insert(i);
    }
    cout << r << '\n';
    for (int v : ans)
    {
        cout << v << " ";
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