#include <bits/stdc++.h>
using namespace std;

string eraseZero(string s){
    int i;
    for(i = 0; i < s.length(); i++){
        if(s[i] != '0') break;
    }
    string ret = s.substr(i, s.length() - i);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        string s, ret = "";
        char low, high;
        cin >> s;
        cin >> low >> high;

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
                ret = "";
                bool flag2 = false;
                for(int j = 0; j < s.length(); j++){
                    if(flag2){
                        ret += high;
                        continue;
                    }

                    if(s[j] == high){
                        ret += low;
                        flag2 = true;
                    } else if(s[j] == low){
                        ret += low;
                    }
                }
                if(!flag2){
                    ret = "";
                    for(int j = 0; j < s.length() - 1; j++){
                        ret += high;
                    }
                }
                break;
            }
        }

        ret = eraseZero(ret);
        if(ret.length()) cout << "#" << t << " " << ret << "\n";
        else cout << "#" << t << " -1\n";
    }

    return 0;
}
/*
13
1 0 1
12223 1 3
1101 0 1
3333 0 3
3333 0 4
88880 7 8
88808 7 8
77770 7 8
12202 1 2
123456789 1 9
16 1 3
2 6 9
5 0 8
422223324 2 4

3
88880 7 8
88808 7 8
98808 7 8

3 
88880 7 8
88808 7 8
12202 1 2
*/
