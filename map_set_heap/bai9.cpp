#include<iostream>
#include<queue>
#include<set>

#define sz(a) (int)a.size()
using namespace std;

priority_queue<int> qu;

int main(){
    string s;
    while(cin >> s){
        if(s[0] == '-'){
            if(!qu.empty()){
                int tmp = qu.top();
                while(!qu.empty() && qu.top() == tmp)  qu.pop();
            }
        }else{
            int num = 0;
            for(int i=1; i<sz(s); ++i){
                num = num*10 + (s[i] - '0');
            }
            if(sz(qu) < 15000)  qu.push(num);
        }
    }

    set<int> st;
    while(!qu.empty())  st.insert(qu.top()),    qu.pop();
    cout << sz(st) << '\n';
    while(!st.empty()){
        cout << *st.rbegin() << '\n';
        st.erase(prev(st.end()));
    }
    
}