/*
思路：如果两个相同字符连在一起，删除一定是最优的
由于环形结构，最后要检查首尾是否相同，用双端队列处理

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, ans = 0;
    string s;
    cin >> n >> s;
    deque<char>q;
    for (char c : s)
    {
        if (!q.empty())
        {
            if (q.back() == c)
            {
                q.pop_back();
                ans += 2;
                continue;
            }
        }
        q.push_back(c);
    }
    while (q.size() > 1)
    {
        if (q.front() == q.back())
        {
            q.pop_front();
            q.pop_back();
            ans += 2;
        }
        else break;
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