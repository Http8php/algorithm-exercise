/*
const int N = 1e6 + 10;
bool vis[N];
vector<int>p;
void init()
{
    vis[0] = vis[1] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                vis[j] = true;
            }
        }
    }
}
*/