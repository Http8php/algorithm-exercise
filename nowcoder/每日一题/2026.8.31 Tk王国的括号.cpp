/*
标签：栈

思路：删除子串，又能把剩余字符串合并，想到栈
从左往右遍历字符串，与栈顶合并，能消除就消除

时间：O(nlogn)
*/

#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    // 预处理出可以删除的子串
    set<string>st;
    for (int i = 0; i < 13; i++)
    {
        char c1 = 'a' + i, c2 = 'a' + (25 - i);
        string t1;
        t1 += c1;
        t1 += c2;
        st.insert(t1);
        char c3 = 'A' + i, c4 = 'A' + (25 - i);
        string t2;
        t2 += c4;
        t2 += c3;
        st.insert(t2);
    }
    stack<char>stk;
    for (char c : s)
    {
        if (stk.empty()) stk.push(c);
        else
        {
            char c1 = stk.top();
            string t;
            t += c1;
            t += c;
            if (st.count(t)) stk.pop();
            else stk.push(c);
        }
    }
    cout << stk.size();
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