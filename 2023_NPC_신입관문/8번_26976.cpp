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
                for(int j = N - 1; j >= 0; j--){
                    if(ret[j] == '.'){
                        ret[j] = s[i]; ans++;
                        for(int k = i; k <= j; k++){
                            if(s[i] == s[k]) visited[k] = true;
                        }
                        break;
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