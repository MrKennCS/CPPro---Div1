#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    int n;  cin >> n;


    if(n <= 3){
        if(n == 1)  cout << 1;
        else        cout << "NO SOLUTION";
    }
    else if(n == 4){
        cout << "2 4 1 3";
    }else{
        if(n & 1){
            int i=n/2;
            int j=i+2;
            while(i >= 1){
                cout << i << " " << j << " ";
                i -= 1;
                j += 1;
            }
            cout << n/2+1;
        }else{
            for(int i=1; i<=n; i+=2)    cout << i << " ";
            for(int i=2; i<=n; i+=2)    cout << i << " ";
        }
    }
}