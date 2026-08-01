#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool vis[N];
vector<int>p;
void init()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
        }
        for (int x : p)
        {
            if (i * x > N) break;
            vis[i*x] = true;
            if (i % x == 0) break;
        }
    }
}