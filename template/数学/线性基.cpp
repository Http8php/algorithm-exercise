#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int B = 60;
ll b[B+1];
void init()
{
    for (int i = 0; i <= B; i++)
    {
        b[i] = 0;
    }
}
void insert(ll x)
{
    for (int i = B; i >= 0; i--)
    {
        if (((x >> i) & 1) == 0) continue;
        if (b[i] == 0)
        {
            b[i] = x;
            return;
        }
        x ^= b[i];
    }
}