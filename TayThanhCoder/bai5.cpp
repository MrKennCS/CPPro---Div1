#include<iostream>
#include<vector>
#define sz(a) (int)a.size()
using namespace std;

int n, a[25];
long long S, curMoneySum;
vector <int> curMoneySet;
vector <int> res;

void printMoneySet()
{
    for (auto i : curMoneySet) cout << a[i] << " ";
    cout << "\n";
}

void genMoneySet(int pos)
{
    int lastIndex = (curMoneySet.empty() ? 1 : curMoneySet.back());
    for (int i = lastIndex+1; i <= n; i ++)
    {
        curMoneySet.push_back(i);
        curMoneySum += a[i];

        if (curMoneySum >= S)
        {
            if (curMoneySum == S){
                res = curMoneySet;
            }
        }
        else genMoneySet(pos + 1);

        curMoneySet.pop_back();
        curMoneySum -= a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> n >> S;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    curMoneySet.clear();
    curMoneySum = 0;

    res = vector<int>(25, -1);
    genMoneySet(1);

    if(res == vector<int>(25, -1))  cout << -1;
    else{
        for(int i=0; i<sz(res); ++i)    cout << a[res[i]] << " ";
    }
    return 0;
}
