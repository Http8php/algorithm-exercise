### 标签
构造，模拟

### 思路
奇偶性相同，即要么全奇，要么全偶。
由于奇 $+$ 奇 $=$ 偶，所以全奇的构造方式是先各填入 $1,3,5$，然后尝试两个两个填奇数，最后填偶数。
全偶的构造方式相同，只是一开始不用填奇数。
注意如果 $abc$ 其中一个数量是 $0$，只能全偶。两种构造方式都失败了，说明没有构造方式，输出 $-1$。

### 时间
$O(n)$

赛时写了两百多行代码，现在优化了一个分支，感觉还是很多
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int>cnt(3);
    vector<queue<int> >ans(3);
    for (char c : s)
    {
        cnt[c-'a']++;
    }
    int c1 = n / 2, c2 = (n + 1) / 2;
    bool ok = true;
    // 尝试全偶
    if ((c2 & 1) == 0)
    {
        int cur = 1;
        while (cur <= n)
        {
            if (cnt[0] > 1)
            {
                ans[0].push(cur);
                cur += 2;
                ans[0].push(cur);
                cur += 2;
                cnt[0] -= 2;
            }
            else if (cnt[1] > 1)
            {
                ans[1].push(cur);
                cur += 2;
                ans[1].push(cur);
                cur += 2;
                cnt[1] -= 2;
            }
            else if (cnt[3] > 1)
            {
                ans[3].push(cur);
                cur += 2;
                ans[3].push(cur);
                cur += 2;
                cnt[3] -= 2;
            }
            else
            {
                ok = false;
                break;
            }
        }
        for (int i = 2; ok && i <= n; i += 2)
        {
            if (cnt[0])
            {
                ans[0].push(i);
                cnt[0]--;
            }
            else if (cnt[1])
            {
                ans[1].push(i);
                cnt[1]--;
            }
            else
            {
                ans[2].push(i);
                cnt[2]--;
            }
        }
    }
    if ((cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) && !ok)
    {
        cout << -1;
        return;
    }
    // 尝试全奇
    if (!ok || ans[0].empty())
    {
        if (c2 >= 3 && ((c2 - 3) & 1) == 0)
        {
            ans[0].push(1);
            ans[1].push(3);
            ans[2].push(5);
            cnt[0]--, cnt[1]--, cnt[2]--;
            int cur = 7;
            while (cur <= n)
            {
                if (cnt[0] > 1)
                {
                    ans[0].push(cur);
                    cur += 2;
                    ans[0].push(cur);
                    cur += 2;
                    cnt[0] -= 2;
                }
                else if (cnt[1] > 1)
                {
                    ans[1].push(cur);
                    cur += 2;
                    ans[1].push(cur);
                    cur += 2;
                    cnt[1] -= 2;
                }
                else if (cnt[3] > 1)
                {
                    ans[3].push(cur);
                    cur += 2;
                    ans[3].push(cur);
                    cur += 2;
                    cnt[3] -= 2;
                }
                else
                {
                    cout << -1;
                    return;
                }
            }
            for (int i = 2; i <= n; i += 2)
            {
                if (cnt[0])
                {
                    ans[0].push(i);
                    cnt[0]--;
                }
                else if (cnt[1])
                {
                    ans[1].push(i);
                    cnt[1]--;
                }
                else
                {
                    ans[2].push(i);
                    cnt[2]--;
                }
            }
        }
        else
        {
            cout << -1;
            return;
        }
    }
    for (char c : s)
    {
        if (c == 'a')
        {
            cout << ans[0].front() << " ";
            ans[0].pop();
        }
        else if (c == 'b')
        {
            cout << ans[1].front() << " ";
            ans[1].pop();
        }
        else
        {
            cout << ans[2].front() << " ";
            ans[2].pop();
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