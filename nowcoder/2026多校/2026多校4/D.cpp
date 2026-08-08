/*
标签：博弈、贪心

思路：由于最后输出字典序最小的循环移位序列，1一定在开头
那么1后的值直接决定了字典序，Alice会填当前最小值，Bob会填当前最大值

奇偶分类讨论
偶数n=2m：设Alice要第二个位置<=k，需要抢先消掉>k的数
Alice要消的数{k+1...2m}，2m-k个数 <= Bob可以干扰的回合
即Bob要消的数{2...k-1}，k-2个数与写下1占用的回合
2m-k<=(k-2)+1 -> 2k>=2m+1 -> k>=m+1/2 由于k必须是整数 k>=m+1
同理，Bob处第二个位置>=m+1，第二个位置=m+1
谁先写1谁劣，所以偶数下1会由Bob填在最后一格
在之前，m+1是开头，Alice会从她要填的最小值开始填，Bob会从他要填的最大值开始填
偶数答案：1, m+1, m, m+2, m−1, m+3,..., 2, 2m

奇数n=2m+1：设Bob要第二个位置>=k，需要抢先消掉<k的数
Bob要消的数{2...k-1}，k-2个数 <= Alice可以干扰的回合
即Alice要消的数{k...2m+1}，(2m+1)-(k-1)个数
k-2<=2m-k+2 -> 2k<=2m+4 -> k<=m+2
同理，Alice处第二个位置<=m+2，第二个位置=m+2
在之前，Alice会从她要填的最小值2开始填，Bob会从他要填的最大值开始填
奇数答案：1, m+2, 2, m+1, m+3, m, m+4,..., 3, 2m+1

时间：O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        int m = n / 2;
        cout << 1 << " ";
        int a = m + 1, b = m;
        for (int i = 1; i < n; i++)
        {
            cout << (i % 2 ? a++ : b--) << " ";
        }
        cout << '\n';
    }
    else
    {
        int m = n / 2;
        cout << 1 << " ";
        int a = m + 2, b = m + 3;
        for (int i = 1; i < n; i++)
        {
            if (i == 2)
            {
                cout << 2 << " ";
                continue;
            }
            cout << (i % 2 ? a-- : b++) << " ";
        }
        cout << '\n';
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