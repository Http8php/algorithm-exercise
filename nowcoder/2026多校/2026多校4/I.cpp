/*
标签：KMP

思路：设|S|=n,|Tk|=m,Tk出现x次(包括跨越首尾)，答案有以下规律：
0, x=0
n-m+1, x=1
n, x>=2
可用KMP加速匹配

单组时间：O(2n + m)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
string s1, s2;
int n, m, nxt[N];
void build()
{
    int cur = 0, i = 1;
    while (i < m)
    {
        if (s2[i] == s2[cur])
        {
            cur++;
            nxt[i] = cur;
            i++;
        }
        else
        {
            if (cur == 0)
            {
                nxt[i] = 0;
                i++;
            }
            else cur = nxt[cur-1];
        }
    }
}
void solve()
{
    int k;
    cin >> s1 >> k;
    s1 += s1;
    s2 = "Rounddo" + string(k, 'g');
    n = s1.length(), m = s2.length();
    build();
    int i = 0, j = 0, cnt = 0;
    while (i < n)
    {
        if (s2[j] == s1[i]) i++, j++;
        else if (j > 0) j = nxt[j-1];
        else i++;
        // 起点在第一个串内
        if (i - m < n / 2 && j == m) cnt++;
    }
    if (cnt == 0) cout << 0 << '\n';
    else if (cnt == 1) cout << n / 2 - m + 1 << '\n';
    else cout << n / 2 << '\n';
    for (int i = 0; i < m; i++)
    {
        nxt[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}