### 思路
保证每场歌两两不同，直接用 $map$ 计数，数量为 $3$ 就输出。

### 时间
$O(nlogn)$

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<string, int>mp;
    for (int i = 1; i <= 3 * n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<string>ans;
    for (auto [v, c] : mp)
    {
        if (c == 3) ans.push_back(v);
    }
    cout << ans.size() << '\n';
    for (string v : ans)
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
```