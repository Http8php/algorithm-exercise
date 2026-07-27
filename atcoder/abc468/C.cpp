/*
思路：注意到n<=10，直接枚举全排列判断即可

时间：O(n * n!)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[i] = i + 1;
    ll ans = 0;
    do
    {
        bool ok1 = false, ok2 = false;
        for (int i = 0; i < n; i++)
        {
            if (c[i] < a[i]) break;
            else if (c[i] > a[i])
            {
                ok1 = true;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (c[i] > b[i]) break;
            else if (c[i] < b[i])
            {
                ok2 = true;
                break;
            }
        }
        if (ok1 && ok2) ans++;
    } while (next_permutation(c.begin(), c.end()));
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