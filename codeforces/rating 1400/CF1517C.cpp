/*
标签：构造

思路：一种构造方法是从右下角沿着主对角线填
这样有n个起点，从每个起点出发，优先向下，不能向下往左一格再判断能否向下，直至填完i个数

时间：O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
int mp[N][N];
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[i][i] = a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        int x = i, y = i;
        int cnt = a[i] - 1;
        while (1)
        {
            while (cnt && x + 1 <= n && mp[x+1][y] == 0)
            {
                mp[x+1][y] = a[i];
                x++;
                cnt--;
            }
            if (cnt && y - 1 >= 1 && mp[x][y-1] == 0)
            {
                mp[x][y-1] = a[i];
                y--;
                cnt--;
            }
            if (cnt == 0) break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << '\n';
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