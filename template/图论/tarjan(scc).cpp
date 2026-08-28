#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
vector<vector<int> >g(N);
int dfn[N], low[N], bel[N];
bool ins[N];
stack<int>st;
int cnt, idx;
void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    ins[u] = true;
    for (int v : g[u])
	{
        if (!dfn[v])
		{
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
		else if (ins[v])
		{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
	{
        idx++;
        int x;
        do
		{
            x = st.top();
			st.pop();
            ins[x] = false;
            bel[x] = idx;
        } while (x != u);
    }
}