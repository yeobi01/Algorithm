#include <bits/stdc++.h>
using namespace std;

int n;
string s, ori_s, pre, suf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> ori_s;
    int pos = ori_s.find('*');
    pre = ori_s.substr(0, pos);
    suf = ori_s.substr(pos+1);

    for(int i = 0; i < n; i++){
        cin >> s;
        if(pre.size() + suf.size() > s.size()){ // 중요한 조건..
            cout << "NE\n";
        } else{
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }

    return 0;
}