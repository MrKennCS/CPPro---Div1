#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, x;
int h[200009];
int pre[200009];
int l, r, mid;
int res;

vector<int> odd(100009, 0);
vector<int> even(100009, 0);
int id1 = 1;
int id2 = 1;

void solve1(){
    cin >> n >> x;

    for(int i=1; i<=n; ++i){
        if(i & 1){  cin >> odd[id1];    id1 += 1;   }
        else     {  cin >> even[id2];   id2 += 1;   }
    }

    /*
    14 5
    1 3 4 2 2 4 3 4 3 3 3 2 3 3


    14 5

    1   4   2   3   3   3   3 
      3   2   4   4   3   2   3

    
    */

    sort(odd.begin() + 1, odd.begin() + id1);
    sort(even.begin()+ 1, even.begin()+ id2);
    
    for(int i=1; i<=n; ++i){
        while()
    }

    /*
    for(int i=1; i<id1; ++i)   cout << odd[i] << " ";  cout << '\n';
    for(int i=1; i<id2; ++i)   cout << even[i]<< " ";  cout << '\n';
    */

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve1();
}