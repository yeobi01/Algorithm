#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while(N--){
        string s, ret = "";
        char low, high;
        cin >> s >> low >> high;

        bool flag = false;
        for(int i = 0; i < s.length(); i++){
            if(flag){
                ret += (high + '0');
                continue;
            }

            if(s[i] >= high){
                ret += (high + '0');
            } else if(high > s[i] && s[i] > low){
                ret += (low + '0');
                flag = true;
            } else if(low == s[i]){
                ret += (low + '0');
            } else if(low > s[i] && s[i] >= 0){
                ret += '0';
            }
        }

        cout << ret << "\n";
    }

}