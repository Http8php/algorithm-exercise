#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int>z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (z[i-l] < r - i + 1) z[i] = z[i-l];
        else
        {
            z[i] = max(r - i + 1, 0);
            while (i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            l = i, r = i + z[i] - 1;
        }
    }
}