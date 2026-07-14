#include <bits/stdc++.h>
using namespace std;

#define eps 1e-6
#define debug(x) cout << x << '\n';

using ll = long long;
using ull = unsigned long long;

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

vector<pair<int, int> >p1 = {{0, 1}, {0, -1}};
vector<pair<int, int> >p2 = {{-1, 0}, {1, 0}};
vector<pair<int, int> >p3 = {{-1, -1}, {1, 1}};
vector<pair<int, int> >p4 = {{1, -1}, {-1, 1}};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

/*
bool ok;
cout << (ok ? "Yes" : "No") << '\n';

cout << fixed << setprecision(6);

printf("? %d %d\n", i, j);
printf("! %d\n", ans);
fflush(stdout);
*/