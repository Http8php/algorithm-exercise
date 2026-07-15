/*
知识点：树

思路：要形成一棵树的前提是每个点至少有一条边，只有满足p中u的索引小于v的索引且u<v才可以连边
从1入手，发现1在数列最后肯定不行，因为前面没有比它小的数(排列)
要让1脱困，解决办法是1后有数，且这个数需要大于前面的某个数
此时可以想到维护后缀最大值和前缀最小值进行比较
由于每个点的情况与1类似，可以扫一遍数组，一旦后缀最大值小于前缀最小值，直接No

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    // 前缀最小值 后缀最大值
    vector<int>pre(n + 1), suf(n + 2);
    // 初始化，不然前缀最小值均为0了
    pre[0] = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = min(pre[i-1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = max(suf[i+1], a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        // 当前最小值 > 之后最大值
        if (pre[i] > suf[i+1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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