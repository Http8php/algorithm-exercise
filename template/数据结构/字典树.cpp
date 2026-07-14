#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int tot = 1, ans;
int tr[N][65], cnt[N];
bool exist[N];
void init()
{
    for (int i = 1; i <= tot; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            tr[i][j] = 0;
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        cnt[i] = 0;
        exist[i] = false;
    }
    tot = 1;
}
int get(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
    else if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    else return c - '0' + 52;
}
void insert(string s)
{
    int cur = 1;
    for (char c : s)
    {
        if (!tr[cur][get(c)]) tr[cur][get(c)] = ++tot;
        cur = tr[cur][get(c)];
        cnt[cur]++;
    }
    exist[cur] = true;
}
int find(string s)
{
    int cur = 1;
    for (char c : s)
    {
        if (!tr[cur][get(c)]) return 0;
        cur = tr[cur][get(c)];
    }
    return cnt[cur];
}