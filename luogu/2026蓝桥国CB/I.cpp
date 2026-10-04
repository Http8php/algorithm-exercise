/*
标签：贪心、不变量

思路：要让字典序最小，0尽量在前，1尽量在后
由于可以移动的条件是一段中1的数量一样，所以需要交换的两段是形如10前、01后
可以发现，让前面的1往后一步的代价是后面的1往前一步
直接模拟是困难的，所以要另想办法
进一步观察1往前往后，发现1位置索引之和sum不变，数量cnt不变
此时可以贪心地摆，从前往后，设当前在i位，显然剩余的位置n-i必须大于等于还没摆的1
最小的sum为i+1...i+cnt这cnt个，用等差数列求和公式求出mn
最大为n-(cnt-1)...n这cnt个，求出mx，如果当前mn=<sum<=mx，这一位就可以填0，反之填1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    ll cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            cnt++;
            sum += i;
        }
    }
    string ans;
    for (int i = 1; i <= n; i++)
    {
        if (n - i < cnt)
        {
            ans += '1';
            cnt--;
            sum -= i;
            continue;
        }
        ll mn = (i + 1 + i + cnt) * cnt / 2;
        ll mx = (n - cnt + 1 + n) * cnt / 2;
        if (sum >= mn && sum <= mx)
        {
            ans += '0';
        }
        else
        {
            ans += '1';
            cnt--;
            sum -= i;
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