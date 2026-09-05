#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int phi[N];
bool vis[N];
vector<int>p;
void init()
{
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (int x : p)
        {
            if (i * x >= N) break;
            vis[i*x] = true;
            if (i % x == 0)
            {
                phi[x*i] = phi[i] * x;
                break;
            }
            else phi[x*i] = phi[x] * phi[i];
        }
    }
}