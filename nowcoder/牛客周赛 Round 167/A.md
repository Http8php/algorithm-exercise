### 思路
按题意模拟。

### 时间
$O(L)$ 其中 $L$ 为字符串长度

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (s[n-1] == 's' && s[n-2] == 'e')
    {
        s.pop_back();
        s.pop_back();
    }
    if (s[n-1] == 's')
    {
        s.pop_back();
    }
    cout << s;
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