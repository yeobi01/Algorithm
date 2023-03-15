#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N;
int check[4][26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < 4; i++){
        string s; cin >> s;
        for(char c : s){
            check[i][c - 'A'] = true;
        }
    }
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        vector<int> v(4); v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3;
        bool flag;
        do{
            flag = true;
            for(int i = 0; i < s.size(); i++){
                if(!check[v[i]][s[i] - 'A']) { flag = false; }
            }
            if(flag) break;
        }while(next_permutation(v.begin(), v.end()));
        flag ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}