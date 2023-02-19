#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807;

ll N, H_atk, _max;
ll arr[200000][3];

bool check(ll H_hp){
    ll atk = H_atk;
    ll hp = H_hp;
    for(int i = 0; i < N; i++){
        ll a = arr[i][1];
        ll h = arr[i][2];
        if(arr[i][0] == 1){
            ll div = (h / atk + (h % atk ? 1 : 0)) - 1;
            hp -= div * a;
            if(hp <= 0) return false;
        } else{
            atk += a;
            hp += h;
            if(hp > H_hp) hp = H_hp;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H_atk;
    for(int i = 0; i < N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    ll low = 0, high = INF, mid, ret;
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ret = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}