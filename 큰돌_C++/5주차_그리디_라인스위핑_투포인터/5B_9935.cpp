#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

string s, tnt, ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> tnt;
    for(char c : s){
        ret += c;
        if(ret.size() >= tnt.size() && ret.substr(ret.size() - tnt.size()) == tnt){
            ret.erase(ret.end() - tnt.size(), ret.end());
        }
    }
    if(!ret.size()) cout << "FRULA\n";
    else cout << ret << "\n";

    return 0;
}