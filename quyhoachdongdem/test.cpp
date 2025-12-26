#include <bits/stdc++.h>

using namespace std;

const string NAME = "test";

const int NTEST = 10000;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".INP").c_str());

        int n = Rand(1, 500);
        inp << n;

        inp.close();

        system((NAME + "_solve.exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (system(("fc " + NAME + ".OUT " + NAME + ".ANS").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
