/*
思路：题干比较难以理解，大意是无论对面怎么选数，我们都能分配，使两侧和一样
形如11223344是最简单反例
设前两轮选了左侧元素{P,Q}，右侧元素{R,S}
后两轮{P,Q}{R,S}，差值为(P+Q-R-S)±(P−Q)±(Q−S)不等于0
只要元素种类>3就没有策略

时间：O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    set<int>s;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cout << (s.size() <= 3 ? "YES" : "NO");
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