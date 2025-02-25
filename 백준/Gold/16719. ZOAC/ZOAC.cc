// 16719번. ZOAC

#include <bits/stdc++.h>
using namespace std;

string s;
int str[100], str_len, start = 0;
bool visited[100];
bool res[100][100];
int cnt = 0;

void f(int start){
    while(1){
        int min = 999, min_idx = -1;
        for(int i = start; i < str_len; i++){
            if(!res[cnt][i] && str[i] < min){
                min = str[i];
                min_idx = i;
            }
        }
        if(min_idx != -1){
            res[cnt][min_idx] = true;
            cnt++;
            for(int i = 0; i < str_len; i++) res[cnt][i] = res[cnt - 1][i];
            f(min_idx);
        } else{
            break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s; str_len = s.length();
    for(int i = 0; i < str_len; i++){
        str[i] = s[i] - 'A' + 1;
        // cout << str[i] << " ";
        if(str[i] < str[start]) start = i; // 시작점 찾기
    } // cout << "\n";

    // cout << start << "\n";
    
    // res[0][start] = true;
    // cnt++;
    // for(int i = 0; i < str_len; i++) res[cnt][i] = res[cnt - 1][i];
    f(0);

    for(int i = 0; i < str_len; i++){
        for(int j = 0; j < str_len; j++){
            if(res[i][j]) cout << (char)(str[j] + 'A' - 1);
        } cout << "\n";
    }

    return 0;
}

