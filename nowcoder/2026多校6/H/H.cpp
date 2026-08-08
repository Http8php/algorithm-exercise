/*
标签：可以使用next_permutation打表出答案
规律是x-1是质数的情况把后四位翻转
也很好理解，字典序最小，前面差距都是1，只看首尾，x-4一定不是质数(除了6)

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x)
{
    if (x == 1 || x == 0) return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    if (n == 3 || n == 4 || n == 6)
    {
        cout << -1 << '\n';
        return;
    }
    if (check(n - 1))
    {
        for (int i = 1; i <= n - 4; i++)
        {
            cout << i << " ";
        }
        for (int i = n; i > n - 4; i--)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
    }
    cout << '\n';
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