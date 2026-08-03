/*
思路：按题意模拟
注意立方体读入顺序

时间：O(a^3)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mp[110][110][110];
void solve()
{
    int a;
    cin >> a;
    for (int k = 0; k < a + 1; k++)
    {
        for (int i = 0; i < a + 1; i++)
        {
            for (int j = 0; j < a + 1; j++)
            {
                cin >> mp[i][j][k];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= a; i++)
    {
        ans += mp[i][i][i];
    }
    int x = 0, y = 0, z = a;
    for (int i = 0; i <= a; i++)
    {
        ans += mp[x+i][y+i][z-i];
    }
    x = a, y = 0, z = a;
    for (int i = 0; i <= a; i++)
    {
        ans += mp[x-i][y+i][z-i];
    }
    x = a, y = 0, z = 0;
    for (int i = 0; i <= a; i++)
    {
        ans += mp[x-i][y+i][z+i];
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