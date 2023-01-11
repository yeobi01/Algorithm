#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

ll A, B;
ll d[55];

ll go(ll x){
    ll ans = x & 1;
    for(int i = 54; i > 0; i--){
        if(x & (1LL << i)){
            ans += d[i - 1] + (x - (1LL << i) + 1);
            x &= ~(1LL << i);
        }
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    d[0] = 1;
    for(ll i = 1; i < 55; i++){
        d[i] = d[i - 1] * 2 + (1LL << i);
    }
    cin >> A >> B;
    cout << go(B) - go(A - 1);

    return 0;
}