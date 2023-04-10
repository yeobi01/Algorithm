#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int N, dp[40004];
bool primeNum[40004];

void prime(){
    for(int i = 2; i <= 40000; i++){
        primeNum[i] = true;
    }
    for(int i = 2; i <= sqrt(40000); i++){
        if(!primeNum[i]) continue;
        for(int j = i * i; j <= 40000; j += i) primeNum[j] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    prime();
    dp[0] = 1;
    for(int i = 0; i <= 40000; i++){
        if(primeNum[i]){
            for(int j = i; j <= 40000; j++){
                dp[j] = (dp[j] + dp[j - i]) % 123456789;
                dp[j] %= 123456789;
            }
        }
    }
    cin >> N;
    cout << dp[N] << "\n";
    return 0;
}