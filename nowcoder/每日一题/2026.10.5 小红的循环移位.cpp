/*
小trick：一个数能被4整除的判断方法是后2位组成的数能被4整除

思路：用一个指针i模拟当前循环移位的倒数第二位，j=(i+1)%n即为下一位
i从n-2开始，由于一共n个循环移位，i要移动到(n-2)+(n-1)=2n-3为止
维护一个计数器，i%n和j就是当前循环移位的最后两位，如果能被4整除，输出即可

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    for (int i = n - 2; i <= 2 * n - 3; i++)
    {
        int ni = i % n;
        int j = (ni + 1) % n;
        if (((s[ni] - '0') * 10 + (s[j] - '0')) % 4 == 0)
        {
            cout << ans;
            return;
        }
        ans++;
    }
    cout << -1;
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