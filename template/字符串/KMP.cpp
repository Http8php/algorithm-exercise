#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s1, s2;
int n, m, nxt[N];
void build()
{
    int cur = 0, i = 1;
    while (i < m)
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
    cin >> s1 >> s2;
    n = s1.length(), m = s2.length();
    build();
    int i = 0, j = 0;
    while (i < n)
    {
        if (s2[j] == s1[i]) i++, j++;
        else if (j > 0) j = nxt[j-1];
        else i++;
        if (j == m) cout << i - j << '\n';
    }
}