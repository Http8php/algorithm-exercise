/*
标签：枚举、二维前缀和

思路：n×m大方格内可以切出若干个k×k小方格，任务是找到内部有1的小方格数量
将左上角的点代表小方格，右下角的点即为(i+k-1,j+k-1)，这样最多枚举n×m个
内部有1转换成和大于0，用二维前缀和快速实现

时间：O(mn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int a[N][N], sum[N][N];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            if (sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1] > 0) ans++;
        }
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