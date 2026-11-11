### 标签
构造

### 思路
打表发现 $[1,n]$ 总能很快找到 $x$ 的答案，直接暴力找 $n$ 即可。

正解是 $[1,2x+1]$，长度为 $2x+1\ge3$，这个区间的和为 $\frac{(1+2x+1)\times(2x+1)}{2}=(x+1)(2x+1)$，这两个数都和 $x$ 互质，所以构造成立。

### 正解时间
$O(1)$

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int x;
    cin >> x;
    int sum = 3;
    for (int i = 3; ; i++)
    {
        sum += i;
        if (gcd(x, sum) == 1)
        {
            cout << 1 << " " << i;
            return;
        }
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