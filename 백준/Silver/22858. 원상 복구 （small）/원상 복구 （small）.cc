#include <bits/stdc++.h>
using namespace std;

int N, K;
int S[10001], D[10001];
int temp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> S[i];
    for(int i = 1; i <= N; i++) cin >> D[i];

    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= N; j++){
            temp[D[j]] = S[j];
        }
        for(int j = 1; j <= N; j++) S[j] = temp[j];
    }
    
    for(int i = 1; i <= N; i++){
        cout << S[i] << " ";
    }
    cout << "\n";

    return 0;
}
