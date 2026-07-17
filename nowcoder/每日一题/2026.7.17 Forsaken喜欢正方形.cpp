/*
思路：判断正方形可以记录四个点连出的六条边，若有四条一样长并且剩下两条也一样长，则是正方形
初始不是正方形，就枚举四个点可以微调的位置再判断

时间：O(1)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check(vector<int>x, vector<int>y)
{
    map<int, int>e;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (i == j) continue;
            int len = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            e[len]++;
        }
    }
    bool ok2 = false, ok4 = false;
    for (auto [l, c] : e)
    {
        if (c == 2) ok2 = true;
        else if (c == 4) ok4 = true;
    }
    return (e.size() == 2 && ok2 && ok4);
}
void solve()
{
    vector<int>x(4), y(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i] >> y[i];
    }
    if (check(x, y))
    {
        cout << "wen";
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            vector<int>cx, cy;
            cx = x, cy = y;
            int nx = x[i] + dx[k];
            int ny = y[i] + dy[k];
            cx[i] = nx, cy[i] = ny;
            if (check(cx, cy))
            {
                cout << "hai xing";
                return;
            }
        }
    }
    cout << "wo jue de bu xing";
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