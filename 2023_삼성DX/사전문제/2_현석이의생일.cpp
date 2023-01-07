#include <bits/stdc++.h>
using namespace std;

int T;
char low, high;
string s, ret;

bool check(){
    for(int i = 0; i < s.length(); i++){
        if(s[i] > low) break;
        else if(s[i] == low) continue;
        else if(s[i] < low) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> s;
        cin >> low >> high;
        ret = "";

        if(!check()){
            for(int j = 0; j < s.length() - 1; j++){
                ret += high;
            }
            if(ret.size()) cout << "#" << t << " " << ret << "\n";
            else cout << "#" << t << " -1\n";
            continue;
        }

        bool flag = false;
        for(int i = 0; i < s.length(); i++){
            if(flag){
                ret += high;
                continue;
            }
            if(s[i] > high){
                ret += high;
                flag = true;
            } else if(s[i] == high){
                ret += high;
            } else if(high > s[i] && s[i] > low){
                ret += low;
                flag = true;
            } else if(s[i] == low){
                ret += low;
            } else if(low > s[i]){
                int j;
                for(j = i - 1; j >= 0; j--){
                    if(ret[j] == high){
                        ret[j] = low;
                        break;
                    } else{
                        ret[j] = high;
                    }
                }
                ret += high;
                flag = true;
            }
        }

        if(ret[0] == '0') ret = ret.substr(1, ret.size() - 1);

        if(ret.length()) cout << "#" << t << " " << ret << "\n";
        else cout << "#" << t << " -1\n";
    }
    return 0;
}
/*
14
1 0 1
12223 1 3
1101 0 1
3333 0 3
3333 0 4
88880 7 8
78808 7 8
77770 7 8
12202 1 2
123456789 1 9
16 1 3
2 6 9
5 0 8
422223324 2 4
*/