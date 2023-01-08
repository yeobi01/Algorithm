#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        getline(cin, s);

        if(s == ".") break;

        stack<char> stk; bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '['){
                stk.push(s[i]);
            } else if(s[i] == ')'){
                if(stk.empty() || stk.top() != '(') { flag = false; break; };
                stk.pop();
            } else if(s[i] == ']'){
                if(stk.empty() || stk.top() != '[') { flag = false; break; };
                stk.pop();
            }
        }
        if(flag && stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}