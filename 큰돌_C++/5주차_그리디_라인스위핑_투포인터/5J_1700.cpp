#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, K, arr[104], visited[104], cnt;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++) cin >> arr[i];
    for(int i = 0; i < K; i++){
        if(!visited[arr[i]]){
            if(v.size() == N){
                int last_idx = 0, pos;
                for(int temp : v){
                    int here_pick = INF;
                    for(int j = i + 1; j < K; j++){
                        if(temp == arr[j]){
                            here_pick = j; break;
                        }
                    }
                    if(last_idx < here_pick){
                        last_idx = here_pick;
                        pos = temp;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(arr[i]); visited[arr[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}