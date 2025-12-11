#include<iostream>

using namespace std;

    int val(char ro){
        switch(ro){
            case 'M':   return 1000;
                break;
            case 'D':   return 500;
                break;
            case 'C':   return 100;
                break;
            case 'L':   return 50;
                break;
            case 'X':   return 10;
                break;
            case 'V':   return 5;
                break;
            default:    return 1;
        }
    }
    int romanToInt(string s) {
        for(int i=0; i<size(s); ++i){
            cout << val(s[i]);
        }
        return 0;
    }

int main(){
    string s;   cin >> s;
    romanToInt(s);
}