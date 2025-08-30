#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, x;
int h[200009];
int pre[200009];
int l, r, mid, mid_id1, mid_id2;

vector<int> odd(100009, 0);
vector<int> even(100009, 0);
int id1 = 1;
int id2 = 1;
int res1 = 200009;
int res2;

void solve1(){
    cin >> n >> x;

    for(int i=1; i<=n; ++i){
        if(i & 1){  cin >> odd[id1];    id1 += 1;   }
        else     {  cin >> even[id2];   id2 += 1;   }
    }

    id1 -= 1;
    id2 -= 1;

    /*
    14 5
    1 3 4 2 2 4 3 4 3 3 3 2 3 3


    14 5

    1   4   2   3   3   3   3 
      3   2   4   4   3   2   3
    */

    //cout << id1 << " " << id2 << '\n';

    sort(odd.begin() + 1, odd.begin() + id1 + 1);
    sort(even.begin()+ 1, even.begin()+ id2 + 1);
    

    // truong hop odd
    for(int i=1; i<=x; ++i){
        // tim vi tri odd[i] be nhat ma >= i
        l = 1;
        r = id1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(odd[mid] >= i){
                mid_id1 = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }
        // khi nay thi id1 - mid_id1 + 1 se la so chuong ngai vat con ong phai di qua
        if(i > odd[id1])    mid_id1 = mid + 1;
        if(i == odd[id1] && mid_id1 == id1) mid_id1 = id1;
        //cout << mid_id1 << " " << id1 - mid_id1 + 1 << '\n';

        l = 1;
        r = id2;

        int j = x - i + 1;

        while(l <= r){
            mid = (l + r) >> 1;
            if(even[mid] >= j){
                mid_id2 = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }
        if(j > even[id2])    mid_id2 = mid + 1;
        if(j == even[id2] && mid_id2 == id2) mid_id2 = id2;
        //cout << mid_id2 << " " << id2 - mid_id2 + 1 << '\n';
        
        //cout << id1 - mid_id1 + 1 << " " << id2 - mid_id2 + 1 << '\n';
        if(res1 >= id1 - mid_id1 + id2 - mid_id2 + 2){
            if(res1 == id1 - mid_id1 + id2 - mid_id2 + 2)   res2 += 1;
            else{
                res1 = id1 - mid_id1 + id2 - mid_id2 + 2;
                res2 = 1;
            }
        }


    }
    cout << res1 << " " << res2;

    /*
    1 2 3 3 3 4 
    2 2 3 3 4 4
    */
    /*
    for(int i=1; i<=id1; ++i)   cout << odd[i] << " ";  cout << '\n';
    for(int i=1; i<=id2; ++i)   cout << even[i]<< " ";  cout << '\n';
    */

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve1();
}