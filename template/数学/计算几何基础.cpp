#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-9;
struct vec
{
    double x, y;
    friend vec operator+(vec a, vec b)
    {
        return {a.x + b.x, a.y + b.y};
    }
    friend vec operator-(vec a, vec b)
    {
        return {a.x - b.x, a.y - b.y};
    }
    friend vec operator*(double k, vec a)
    {
        return {k * a.x, k * a.y};
    }
};
using point = vec;
struct circle
{
    point o;
    double r;
};
bool cmp(point a, point b)
{
    if (abs(a.x - b.x) > eps) return a.x < b.x;
    return a.y < b.y;
}
double dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}
double dis(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

// Andrew 凸包
bool check(point p, point q, point r)
{
    return cross(q - p, r - p) > eps;
}
vector<point>ps;
void andrew()
{
    sort(ps.begin(), ps.end(), cmp);
    int n = ps.size();
    vector<int>s;
    for (int i = 0; i < n; i++)
    {
        while (s.size() > 1 && !check(ps[s[s.size()-2]], ps[s.back()], ps[i]))
        {
            s.pop_back();
        }
        s.push_back(i);
    }
    int t = s.size();
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.size() > t && !check(ps[s[s.size()-2]], ps[s.back()], ps[i]))
        {
            s.pop_back();
        }
        s.push_back(i);
    }
    vector<point>H;
    for (int x : s)
    {
        H.push_back(ps[x]);
    }
}