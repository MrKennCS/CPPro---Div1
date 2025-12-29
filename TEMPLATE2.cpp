#include <bits/stdc++.h> //hôm nay zui vãi ò (*^▽^*)(≧∇≦)ﾉ♪(^∇^*)
#define ll long long
#define ull unsigned ll
#define uint unsigned int
#define ld long double
#define int128 __int128_t
#define fi first
#define se second
#define get_bit(n, k) ((n >> k) & 1LL)
#define on_bit(n, k) (n | (1LL << k))
#define off_bit(n, k) (n & (~(1LL << k)))
#define toggle_bit(n, k) (n ^ (1LL << k))
#define matran vector <vector<ll>>
#define pii pair <int, int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
using namespace std;
const ll nmax = 1e5, mod = 1e9 + 7;
int a[nmax + 7], pref[nmax + 7][3];
struct bell
{
    int c1, c2;
};
int main()
{
    if(fopen("seldig.inp", "r"))
    {
        freopen("seldig.inp", "r", stdin);
        freopen("seldig.out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q, x, y;
    cin>>n>>q>>x>>y;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        for(int j = 0; j < 3; j++)
        {
            pref[i][j] = pref[i - 1][j] + (a[i] == j);
        }
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int c0 = pref[r][0] - pref[l - 1][0],
            c1 = pref[r][1] - pref[l - 1][1],
            c2 = pref[r][2] - pref[l - 1][2];
        int len = r - l + 1;
        map <pii, int> dist;
        queue <bell> q;
        dist[{c1, c2}] = 0;
        q.push({c1, c2});
        int ans = -1;
        while(!q.empty())
        {
            auto cur = q.front();
            int d = dist[{cur.c1, cur.c2}];
            q.pop();
            if(cur.c1 == 0 && cur.c2 == 0)
            {
                ans = d;
                break;
            }
            int curc0 = len - cur.c1 - cur.c2;
            for(int x1 = 0; x1 <= x; x1++)
            {
                for(int x2 = 0; x2 <= x - x1; x2++)
                {
                    int x0 = x - x1 - x2;
                    if(x0 > curc0 || x1 > cur.c1 || x2 > cur.c2)
                    {
                        continue;
                    }
                    for(int y1 = 0; y1 <= y; y1++)
                    {
                        for(int y2 = 0; y2 <= y - y1; y2++)
                        {
                            int y0 = y - y1 - y2;
                            if(y0 > curc0 - x0 || y1 > cur.c1 - x1 || y2 > cur.c2 - x2)
                            {
                                continue;
                            }
                            int nc0 = curc0 - x0 - y0 + x2 + y1,
                            nc1 = cur.c1 - x1 - y1 + x0 + y2,
                            nc2 = cur.c2 - x2 - y2 + x1 + y0;
                            if(nc1 < 0 || nc2 < 0)
                            {
                                continue;
                            }
                            auto nxt = make_pair(nc1, nc2);
                            if(!dist.count(nxt))
                            {
                                dist[nxt] = d + 1;
                                q.push({nc1, nc2});
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
