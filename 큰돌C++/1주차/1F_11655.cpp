#include <bits/stdc++.h>
using namespace std;

string s;

// A : 65 N : 78 Z : 90 
// a : 97 n : 110 z : 122

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    for(int i = 0; i < s.size(); i++){
        if( (s[i] >= 65 && s[i] <=  77) || (s[i] >= 97 && s[i] <= 109) ){
            s[i] += 13;
        } else if ( (s[i] >= 78 && s[i] <=  90) || (s[i] >= 110 && s[i] <= 122) ){
            s[i] -= 13;
        }
    }

    cout << s << "\n";

    return 0;
}