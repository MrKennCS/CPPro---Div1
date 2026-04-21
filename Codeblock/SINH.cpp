#include<bits/stdc++.h>

using namespace std;

const string NAME = "";
const int TEST = 100;

mt19937 rng(7405);
mt19937 rng2(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return abs((int)rng() % (r - l + 1)) + l;
}

void generate_test(){
    ofstream inp((NAME + ".inp").c_str());



    inp.close();
}

bool check_test(){
    if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0){
        return 0;
    }else{
        return 1;
    }
}

bool general_check_test(){
    ifstream out1((NAME + ".out").c_str());
    ifstream out2((NAME + ".ans").c_str());
}

void process(){
    for(int itest = 1; itest <= TEST; itest++){
        generate_test();

        system((".\\" + NAME + ".exe").c_str());
        system((".\\" + NAME + "_trau.exe").c_str());
        bool ok = check_test();
        if(!ok){
            cout << "TEST " << itest << ": WA\n";
            exit(0);
        }
        else{
            cout << "TEST " << itest << ": AC\n";
        }
    }
}

signed main(){
    // Việc không để ios_base::sync_with_stdio(0)/cin.tie(0) là để dễ xem trạng thái của từng test
    process();
}
