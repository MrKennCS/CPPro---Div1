#include<iostream> 
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define sz(a) (int)a.size()
using namespace std;

int n;
int res;
string s;
unordered_map<int, int> cnt;
vector<int> state;
queue<string> qu;

void backtrack(){
    for(int i=97; i<=122; ++i){
        if(cnt[i] > 0)  state.push_back(i);
        else            continue;

        cnt[i]--;

        if(sz(state) == n){
            string str = "";
            res++;
            for(int j=0; j<n; ++j){
                str += char(state[j]);
                //cout << char(state[j]);
            }
            //cout << '\n';
            qu.push(str);
        }else   backtrack();

        state.pop_back();
        cnt[i]++;
    }
}

void solve(){
    cin >> s;
    n = sz(s);
    for(int i=0; i<n; ++i)  cnt[s[i]]++;
    /*
    for(int i='a'; i<='z'; ++i){
        if(cnt[i] > 0)  cout << char(i) << " " << cnt[i] << '\n';
    }
    */
    backtrack();
    cout << res << '\n';
    while(!qu.empty()){
        cout << qu.front() << '\n';
        qu.pop();
    }
    //cout << (int)'a' << " " << (int)'z' << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}