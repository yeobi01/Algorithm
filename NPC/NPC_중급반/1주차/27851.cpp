#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll N, K, d[100001], ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }

    ll temp = 0;
    for(int i = 0; i < N - 1; i++){
        if(K + 1 < (d[i + 1] - d[i])){
            ret += 1 + K + temp;
            temp = 0;
        } else {
            temp += d[i + 1] - d[i];
        }
    }
    if(temp > 0){
        ret += 1 + K + temp;
    } else {
        ret += 1 + K;
    }
    cout << ret << "\n";
    return 0;
} 