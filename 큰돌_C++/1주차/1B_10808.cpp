#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(char a : s){
        cnt[a-'a']++;
    }
    
    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";

    return 0;
}