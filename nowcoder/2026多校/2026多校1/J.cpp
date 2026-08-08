/*
知识点：枚举，博弈，模拟

思路：先考虑必胜策略，由于赌神先手，找到赌神最大暗牌p1，我们最大暗牌c1和次大暗牌c2
如果赌神用p1大于我们用c1或者赌神用c1大于我们c2，赌神必赢
如果赌神用p1小于我们用c1并且赌神用c1小于我们c2，我们必赢
开始枚举，找到p1, c1, c2，其中比较先比牌型，再比大小

时间：O(52) 有大常数
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string ranks = "23456789TJQKA";
const string suits = "CDHS";
int getnum(string s)
{
    if (s[0] >= '2' && s[0] <= '9') return (s[0] - '0');
    if (s[0] == 'T') return 10;
    if (s[0] == 'J') return 11;
    if (s[0] == 'Q') return 12;
    if (s[0] == 'K') return 13;
    return 14;
}
int getcolor(string s)
{
    if (s[1] == 'C') return 0;
    if (s[1] == 'D') return 1;
    if (s[1] == 'H') return 2;
    return 3;
}
struct node
{
    int type;
    vector<int>cards;
};
// 判断当前手牌类型，返回题目要求的比大小顺序
node trans(vector<string>p)
{
    vector<int>r(5), s(5);
    for (int i = 0; i < 5; i++)
    {
        r[i] = getnum(p[i]);
        s[i] = getcolor(p[i]);
    }
    int cnt[15] = {0}, sc[4] = {0};
    for (int i = 0; i < 5; i++)
    {
        cnt[r[i]]++;
        sc[s[i]]++;
    }
    int flush = -1;
    for (int i = 0; i < 4; i++)
    {
        if (sc[i] == 5) flush = i;
    }
    vector<int>u = r;
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    bool straight = false;
    vector<int>seq;
    if (u.size() == 5)
    {
        if (u[4] - u[0] == 4)
        {
            straight = true;
            seq = u;
        }
        if (u == vector<int>{2, 3, 4, 5, 14})
        {
            straight = true;
            seq = {14, 5, 4, 3, 2};
        }
    }
    if (flush != -1 && straight && u == vector<int>{10, 11, 12, 13, 14}) return {10, {14, 13, 12, 11, 10}};
    if (flush != -1 && straight)
    {
        if (seq == vector<int>{14, 5, 4, 3, 2}) return {9, {5, 4, 3, 2, 1}};
        reverse(seq.begin(), seq.end());
        return {9, seq};
    }
    for (int i = 2; i <= 14; i++)
    {
        if (cnt[i] == 4)
        {
            int k = 0;
            for (int j = 14; j >= 2; j--)
            {
                if (cnt[j] == 1) k = j;
            }
            return {8, {i, i, i, i, k}};
        }
    }
    int three = -1, pair = -1;
    for (int i = 14; i >= 2; i--)
    {
        if (cnt[i] == 3) three = i;
        if (cnt[i] == 2) pair = i;
    }
    if (three != -1 && pair != -1) return {7, {three, three, three, pair, pair}};
    if (flush != -1)
    {
        vector<int>t = r;
        sort(t.rbegin(), t.rend());
        return {6, t};
    }
    if (straight)
    {
        if (seq == vector<int>{14, 5, 4, 3, 2}) return {5, {5, 4, 3, 2, 1}};
        reverse(seq.begin(), seq.end());
        return {5, seq};
    }
    if (three != -1)
    {
        vector<int>k;
        for (int i = 14; i >= 2; i--)
        {
            if (cnt[i] == 1) k.push_back(i);
        }
        return {4, {three, three, three, k[0], k[1]}};
    }
    vector<int>pairs;
    for (int i = 14; i >= 2; i--)
    {
        if (cnt[i] == 2) pairs.push_back(i);
    }
    if (pairs.size() == 2)
    {
        int k = 0;
        for (int i = 14; i >= 2; i--)
        {
            if (cnt[i] == 1) k = i;
        }
        return {3, {pairs[0], pairs[0], pairs[1], pairs[1], k}};
    }
    if (pairs.size() == 1)
    {
        vector<int>k;
        for (int i = 14; i >= 2; i--)
        {
            if (cnt[i] == 1) k.push_back(i);
        }
        return {2, {pairs[0], pairs[0], k[0], k[1], k[2]}};
    }
    vector<int>t = r;
    sort(t.rbegin(), t.rend());
    return {1, t};
}
bool check(node h1, node h2)
{
    if (h1.type != h2.type) return h1.type > h2.type;
    for (int i = 0; i < 5; i++)
    {
        if (h1.cards[i] != h2.cards[i]) return (h1.cards[i] > h2.cards[i]);
    }    
    return false;
}
void solve()
{
    vector<string>a(5), b(5);
    set<string>tot;
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        tot.insert(a[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> b[i];
        tot.insert(b[i]);
    }
    string p1, c1, c2;
    node ep1 = {0, {}}, ec1 = {0, {}}, ec2 = {0, {}};
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string cur = "";
            cur += ranks[i];
            cur += suits[j];
            if (tot.count(cur)) continue;
            a[4] = cur;
            node ec = trans(a);
            b[4] = cur;
            node ep = trans(b);
            // 若当前的牌比较强，先当第二强
            // 再判断能不能当最强，如果是最强，之前的最强当第二强
            if (c2.empty() || check(ec, ec2))
            {
                c2 = cur;
                ec2 = ec;
            }
            if (c1.empty() || check(ec2, ec1))
            {
                swap(c1, c2);
                swap(ec1, ec2);
            }
            if (p1.empty() || check(ep, ep1))
            {
                p1 = cur;
                ep1 = ep;
            }
        }
    }
    b[4] = c1;
    node ep2 = trans(b);
    bool op = false;
    if (check(ep1, (c1 == p1 ? ec2 : ec1))) op = true;
    if (check(ep2, ec2)) op = true;
    if (op)
    {
        cout << "GeiWoCaPiXie\n";
        return;
    }
    bool me = false;
    if (check((c1 == p1 ? ec2 : ec1), ep1) && check(ec2, ep2)) me = true;
    if (me) cout << "WoYaoYanPai\n";
    else cout << "PaiMeiYouWenTi\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}