/*
标签：模拟、字符串

思路：按题意模拟
若发现冲突，把未展开的第一个单词展开

时间：O(mnlognL) m为冲突次数，L为字符串长度
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string>a(n + 1), ans(n + 1);
    // 当前遍历索引 插入索引
    vector<int>idx(n + 1), cnt(n + 1);
    map<string, int>mp, mp2;
    for (int i = 0; i < n; i++)
    {
        string t;
        getline(cin, a[i]);
        for (char c : a[i])
        {
            if (c >= 'A' && c <= 'Z')
            {
                t += c;
            }
        }
        mp[t]++;
        ans[i] = t;
        idx[i] = 1;
        cnt[i] = 1;
    }
    mp2 = mp;
    while (1)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (mp[ans[i]] > 1)
            {
                ok = false;
                mp2[ans[i]]--;
                string t1;
                for (int j = idx[i]; j < a[i].length(); j++)
                {
                    if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                    {
                        idx[i] = j + 1;
                        break;
                    }
                    if (a[i][j] == ' ') continue;
                    t1 += a[i][j];
                }
                string t2 = ans[i];
                // 最后一个单词了
                if (cnt[i] >= t2.length()) t2 += t1;
                else t2.insert(cnt[i], t1);
                cnt[i] += t1.length() + 1;
                mp2[t2]++;
                ans[i] = t2;
            }
        }
        mp = mp2;
        if (ok) break;
    }
    for (string s : ans)
    {
        cout << s << '\n';
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