#include<iostream>

using namespace std;

int n, x;
int a[1000009];
int l, r, mid, res;
void the_smallest_num_that_greater_or_equal_x(){
    /*
    TEST
    10 6
    1 4 5 6 6 6 7 9 10 12
->  4

    10 3
    1 4 5 6 6 6 7 9 10 12
->  2

    10 7
    1 4 5 6 6 6 7 9 10 12
->  7

    10 12
    1 4 5 6 6 6 7 9 10 12
->  10

    10 13
    1 4 5 6 6 6 7 9 10 12
->  0

    10 0
    1 4 5 6 6 6 7 9 10 12
->  1

    10 1
    1 4 5 6 6 6 7 9 10 12
->  1
    */
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i];

    l = 1;
    r = n;

    while(l <= r){
        mid = (l + r) >> 1;
        cout << l << " " << r << '\n';
        if(a[mid] >= x){
            res = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }

    cout << res;
}

void the_biggest_num_that_smaller_or_equal_x(){
    /*
    10 6
    1 4 5 6 6 6 7 9 10 12
->  6

    10 8
    1 4 5 6 6 6 7 9 10 12
->  7

    10 12
    1 4 5 6 6 6 7 9 10 12
->  10

    10 11
    1 4 5 6 6 6 7 9 10 12
->  9

    10 100
    1 4 5 6 6 6 7 9 10 12
->  10

    10 1
    1 4 5 6 6 6 7 9 10 12
->  1

    10 0
    1 4 5 6 6 6 7 9 10 12
->  0
    */
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i];

    l = 1;
    r = n;

    while(l <= r){
        mid = (l + r) >> 1;
        if(a[mid] <= x){
            res = mid;
            l = mid + 1;
        }else   r = mid - 1;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //the_smallest_num_that_greater_or_equal_x();
    the_biggest_num_that_smaller_or_equal_x();
}