#include <bits/stdc++.h>
using namespace std;

int N;
string s, ret;
vector<string> v;

void go(){
    while(true){
        if(ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else break;
    }
    if(ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
    return;
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        ret = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] >= '0' && s[j] <= '9') ret += s[j];
            else if(ret.size()) go();
        }
        if(ret.size()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for(string x : v) cout << x << "\n";
    return 0;
}