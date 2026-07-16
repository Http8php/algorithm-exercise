/*
知识点：KMP

思路：KMP模板题
相当于给定模式串，匹配n个文本串，每次记录模式串最多匹配长度

时间：O(n * (l1 + l2))
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
string s1, s2;
int l2, nxt[N];
void build()
{
    int cur = 0, i = 1;
    while (i < l2)
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
    int n;
    cin >> s2 >> n;
    l2 = s2.length();
    build();
    int ans = 0;
    while (n--)
    {
        cin >> s1;
        int l1 = s1.length();
        int i = 0, j = 0, mx = 0;
        while (i < l1)
        {
            if (s2[j] == s1[i]) i++, j++;
            else if (j > 0) j = nxt[j-1];
            else i++;
            mx = max(mx, j);
        }
        ans += mx;
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