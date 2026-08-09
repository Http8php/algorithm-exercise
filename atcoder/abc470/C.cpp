/*
标签：暴力

思路：操作1只有一个数变，ans=ans^x^(x+1)
操作2数很多，但是只有>=1的数减少
这些数的来源均为操作1，不会多于q次，可以暴力

时间：O(qlogq)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    int ans = 0;
    vector<int>a(n + 1);
    set<int>s;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            ans ^= a[x];
            a[x]++;
            ans ^= a[x];
            s.insert(x);
        }
        else
        {
            vector<int>e;
            for (int p : s)
            {
                ans ^= a[p];
                a[p]--;
                ans ^= a[p];
                if (a[p] == 0) e.push_back(p);
            }
            // 遍历时不能删数，会错乱
            for (int p : e)
            {
                s.erase(p);
            }
        }
        cout << ans << '\n';
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