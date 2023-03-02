#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int T, N, K;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        char ret[100001]; for(int i = 0; i < 100001; i++) ret[i] = '.';
        bool visited[100001]; for(int i = 0; i < 100001; i++) visited[i] = false;
        cin >> N >> K >> s;
        
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(visited[i]) continue;
            if(i + K < N && ret[i + K] == '.'){
                ret[i + K] = s[i]; ans++;
                for(int j = i; j <= i + 2 * K; j++){
                    if(s[i] == s[j]) visited[j] = true;
                }
            } else if(i + K >= N){
                ans++;
                if(ret[i] == '.'){
                    ret[i] = s[i];
                    for(int j = i; j <= N; j++){
                        if(s[i] == s[j]) visited[j] = true;
                    }
                } else if(ret[i] != s[i]){
                    ret[i - 1] = s[i];
                    for(int j = i - 1; j <= N; j++){
                        if(s[i] == s[j]) visited[j] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
        for(int i = 0; i < N; i++) cout << ret[i];
        cout << "\n";
    }
    
    return 0;
}