#include <bits/stdc++.h>
using namespace std;

bool isVowel(int idx){
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string s; cin >> s;
        if(s == "end") break;
        int lcnt = 0, vcnt = 0;
        bool flag = false;
        bool is_include_v = 0;
        int prev = -1;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            if(isVowel(idx)){
                lcnt++;
                vcnt = 0;
                is_include_v = 1;
            } else{
                vcnt++;
                lcnt = 0;
            }
            if(vcnt == 3 || lcnt == 3) flag = true;
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
                flag = 1;
            }
            prev = idx;
        }
        if(is_include_v == 0) flag = 1;
        if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
        else cout << "<" << s << ">" << " is acceptable.\n";
    }

    return 0;
}