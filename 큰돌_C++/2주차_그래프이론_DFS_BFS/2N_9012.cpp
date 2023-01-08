#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> s;
        stack<char> stk; bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') stk.push(s[i]);
            else if(s[i] == ')'){
                if(stk.empty()) { flag = false; break; }
                stk.pop();
            }
        }
        if(flag && stk.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}