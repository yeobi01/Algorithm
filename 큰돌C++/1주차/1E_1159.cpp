#include <bits/stdc++.h>
using namespace std;

int cnt[26], n;
string s, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[s[0]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i] > 4){
            char c = 'a' + i;
            ans += c;
        }
    }
    
    if(ans == "\0") cout << "PREDAJA" << "\n";
    else cout << ans << "\n";

    return 0;
}