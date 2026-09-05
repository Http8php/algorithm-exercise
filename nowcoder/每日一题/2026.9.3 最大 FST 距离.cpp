/*
标签：分类讨论、同构

思路：考虑把绝对值打开
1.(i^2-j^2)+(ai^2-aj^2)
发现可以同构 -> (ai^2+i^2)-(aj^2+j^2) 设为A-B
2.(j^2-i^2)+(aj^2-ai^2) -> B-A
3.(i^2-j^2)+(aj^2-ai^2) -> (aj^2-j^2)-(ai^2-i^2) 设为C-D
4.(j^2-i^2)+(aj^2-ai^2) -> D-C
把a[x]^2+x^2和a[x]^2-x^2都算出后排序，max(abs(mx-mn))就是答案

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll>c1, c2;
    for (ll i = 1; i <= n; i++)
    {
        ll n1 = a[i] * a[i] + i * i;
        c1.push_back(n1);
        ll n2 = a[i] * a[i] - i * i;
        c2.push_back(n2);
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    cout << max(abs(c1[0] - c1[n-1]), abs(c2[0] - c2[n-1]));
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