/*
标签：素数筛、容斥原理、primegap、动态规划

思路：两个数a,b的距离定义为gcd(a, b)，最短的情况是两数互质，dis=1
现在要求 [l, r]->n 的最短路之和，考虑分类讨论
1.最优情况就是i与n互质，贡献答案1，快速处理的办法是容斥原理
2.次优情况找到一个最大质数p(p<=n且p不是n的因子)，i->p->n，贡献答案2
2a.p>=r，n的因子都可以走i->p->n
2b.i∈[l, p)，这一段都可以走i->p->n
2c.i∈(p, r]，不确定
由于1e7内的素数距离最大只有154，可以n^2dp处理
转移：dp[i]=min{dp[j]+gcd(i, j)} j∈[i+1, n)

单组时间：O(m2^m + d^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 10;
bool vis[N];
vector<int>pr;
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
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) pr.push_back(i);
    }
}
// 容斥原理计算[l, r]内与n互质的数的个数
ll calc(int l, int r, int n)
{
    // n的质因子
    vector<int>num;
    int temp = n;
    for (int p : pr)
    {
        if (p * p > temp) break;
        if (temp % p == 0)
        {
            num.push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }
    if (temp > 1) num.push_back(temp);
    int m = num.size();
    // 不互质数的个数
    ll res = 0;
    for (int mask = 1; mask < (1 << m); mask++)
    {
        // 质因子乘积 子集大小
        int sum = 1, c = 0;
        for (int i = 0; i < m; i++)
        {
            if ((mask >> i) & 1)
            {
                sum *= num[i];
                c++;
                if (sum > r) break;
            }
        }
        if (sum > r) continue;
        // 1~r中sum的倍数-1~l-i中sum的倍数
        ll cnt = r / sum - (l - 1) / sum;
        if (c & 1) res += cnt;
        else res -= cnt;
    }
    // 总数-不互质=互质
    return (r - l + 1) - res;
}
void solve()
{
    int l, r, n;
    cin >> l >> r >> n;
    ll ans = 0;
    int pos = upper_bound(pr.begin(), pr.end(), n) - pr.begin() - 1;
    while (pos >= 0 && n % pr[pos] == 0) pos--;
    int p = pr[pos];
    int nr = min(r, p - 1);
    if (l <= nr)
    {
        ll res = calc(l, nr, n);
        ll tot = nr - l + 1;
        ans += res + (tot - res) * 2;
    }
    int nl = max(l, p);
    if (nl <= r)
    {
        int len = n - p + 1;
        vector<int>dp(len + 1, 1e9);
        dp[n-p] = 0;
        for (int x = n - 1; x >= p; x--)
        {
            int idx = x - p;
            dp[idx] = gcd(x, n);
            for (int y = x + 1; y <= n; y++)
            {
                dp[idx] = min(dp[idx], dp[y-p] + gcd(x, y));
            }
        }
        for (int x = nl; x <= r; x++)
        {
            ans += dp[x-p];
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}