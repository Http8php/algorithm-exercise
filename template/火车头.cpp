#include <bits/stdc++.h>
using namespace std;

#define eps 1e-6
#define debug(x) cout << x << '\n';

using i32 = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char op[] = {'U', 'D', 'L', 'R'};

int ddx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ddy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// "米"形拓展
vector<pair<int, int> >p1 = {{0, 1}, {0, -1}};
vector<pair<int, int> >p2 = {{-1, 0}, {1, 0}};
vector<pair<int, int> >p3 = {{-1, -1}, {1, 1}};
vector<pair<int, int> >p4 = {{1, -1}, {-1, 1}};

// 随机数
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

/*
cout << (ok ? "Yes" : "No") << '\n';

cout << fixed << setprecision(6);

printf("? %d %d\n", i, j);
printf("! %d\n", ans);
fflush(stdout);
*/

//判回文
bool check(string s)
{
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

//判素数
bool check(int x)
{
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}