/*
标签：递推、贪心

思路：先按题意计算出p数组的c数组
观察c数组，发现c[i]=0说明此时是极小值点，c[i]=2说明此时是极大值点
0、2不可能有连续段，c数组在{0,1,2}中波动

考虑先处理下降约束，发现每个数往后最多下降2步
设f[i]为第i个数需要下降的步数，通过比较c[i]、c[i+1]和c[i+1]、c[i+2]的关系得到
把a[i]置为1+f[i]，完美符合条件，a[i+2]>=1，且最小a
再处理上升约束，如果c[i]<c[i+1]但是a[i]>=a[i+1]，只要把a[i+1]置为a[i]+1即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<int>c(n + 1);
    c[1] = (p[1] > p[2]);
    for (int i = 2; i < n; i++)
    {
        c[i] = (p[i] > p[i-1]) + (p[i] > p[i+1]);
    }
    c[n] = (p[n] > p[n-1]);
    vector<int>f(n + 1);
    for (int i = 1; i <= n - 2; i++)
    {
        if (c[i] > c[i+1] && c[i+1] > c[i+2]) f[i] = 2;
        else if (c[i] > c[i+1] && c[i+1] <= c[i+2]) f[i] = 1;
    }
    f[n-1] = (c[n-1] > c[n]);
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1 + f[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (c[i] < c[i+1])
        {
            if (a[i] >= a[i+1]) a[i+1] = a[i] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    cout << ans;
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