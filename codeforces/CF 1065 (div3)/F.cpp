/*
标签：树

思路：维护比当前值大的点集合，保证内部连通，第一个区间则为 [a[1], n]，设x=a[1]
遍历排列，当有值>x时，从集合中删除
<x时，如果集合空了，说明不合法，否则连通 [a[i], x)，并额外连一条边a[i]->集合中的最小值，保证区间内连通

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<int>s;
    vector<pair<int, int> >ans;
    int x = a[1];
    s.insert(a[1]);
    for (int i = x + 1; i <= n; i++)
    {
        s.insert(i);
        ans.push_back({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < x)
        {
            if (s.empty())
            {
                cout << "No\n";
                return;
            }
            for (int j = a[i] + 1; j < x; j++)
            {
                ans.push_back({a[i], j});
            }
            ans.push_back({a[i], (*s.begin())});
            for (int j = a[i] + 1; j < x; j++)
            {
                s.insert(j);
            }
            x = a[i];
        }
        else s.erase(a[i]);
    }
    cout << "Yes\n";
    for (auto [u, v] : ans)
    {
        cout << u << " " << v << '\n';
    }
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