// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
// __builtin_popcount
// __builtin_ctz

#define ull unsigned long long
#define ld long double
#define int long long
#define umap unordered_map
#define uset unordered_set

#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound // >=
#define ub upper_bound // >
#define endl '\n'

#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FORE(i,l,r) for(int i=l;i<r;i++)
#define FORNG(i,r,l) for(int i=r;i>=l;i--)
#define REP(x,v) for(auto &x:v) //vector
#define REPD(it, m) for(auto it=m.begin();it != m.end();it++) //map,set
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define nhanh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TIME cerr<<"Time: "<<(1.0 * clock() / CLOCKS_PER_SEC)<<"s.";
//chivy

template<class X,class Y>
    bool minimize(X &x,const Y &y){
        if(x>y){
            x=y;
            return true;
        }
        return false;
    }
template<class X,class Y>
    bool maximize(X &x,const Y &y){
        if(x<y){
            x=y;
            return true;
        }
        return false;
    }

const int MOD=1e9+7,INF=1e18;

void file(const string FILE){
    freopen((FILE+".INP").c_str(),"r",stdin);
    freopen((FILE+".OUT").c_str(),"w",stdout);
}

/* chivy(codeforces) - chivy3103(lqdoj) */

const int MAXN=705;
int n,q,x,y;
int a[MAXN];
int pf[MAXN][3];
int dist[MAXN][MAXN];

struct VOI{
    int a,b,c;
    int d,e,f;
};

vector<VOI> val;

void init(){
    val.clear();
    FOR(a,0,x){
        FOR(b,0,x-a){
            int c=x-a-b;
            FOR(d,0,y){
                FOR(e,0,y-d){
                    int f=y-d-e;
                    val.pb({a,b,c,d,e,f});
                    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
                }
            }
        }
    }
}

void bfs(){
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        int u=q.front().fi;
        int v=q.front().se;
        q.pop();
        REP(x,val){
            int nu=u+x.a+x.d-x.c-x.e;
            int nv=v+x.b+x.e-x.a-x.f;
            if(nu<0||nv<0||nu>n||nv>n) continue;
            if(dist[nu][nv]==-1&&((nu>=x.a+x.d&&nv>=x.b+x.e))){
                dist[nu][nv]=dist[u][v]+1;
                //cout<<nu<<" "<<nv<<" "<<dist[nu][nv]<<endl;
                q.push({nu,nv});
            }
        }
    }
}

void solve(){
    //chivy
    cin>>n>>q>>x>>y;
    pf[0][0]=pf[0][1]=pf[0][2]=0;
    FOR(i,1,n){
        cin>>a[i];
        FOR(j,0,2){
            pf[i][j]=pf[i-1][j]+(a[i]==j);
        }
    }
    init();
    bfs();
    while(q--){
        int l,r;
        cin>>l>>r;
cout<<dist[pf[r][1]-pf[l-1][1]][pf[r][2]-pf[l-1][2]]<<endl;
    }
}

/* Don't copy code :> */
/* Authors: Doan Chi Vy from Thai Phien High School Da Nang */

signed main(){
    nhanh
    file("LIGHT");
    int tt=1;
    //cin>>tt;
    FOR(i,1,tt){
        solve();
    }
    //TIME
}