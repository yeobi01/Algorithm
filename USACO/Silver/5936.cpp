#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll N, Nopt, F, M, ret, memo[200001];
bool FN[40001], flag = false;;
vector<ll> C;

ll go(ll cnt, ll eat){
    if(cnt == 0){
        return eat;
    }

    ll& ans = memo[cnt];
    if(ans == 0){
        cout << "-1\n";
        exit(0);
    }
    if(ans != -1) return ans;

    ans = 0;
    for(ll C_i : C){
        if(cnt - C_i >= 0){
            if(FN[cnt - C_i]){
                ans = max(ans, go(cnt - C_i + M, eat + C_i));
            } else{
                ans = max(ans, go(cnt - C_i, eat + C_i));
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> N >> Nopt >> F >> M;
    for(int i = 0; i < Nopt; i++){
        ll temp; cin >> temp;
        C.push_back(temp);
    }
    for(int i = 0; i < F; i++){
        ll temp; cin >> temp;
        FN[temp] = true;
    }

    ret = go(N, 0);

    cout << ret << "\n";

    return 0;
}

/*
if(cnt == N && flag){
    cout << "-1\n";
    exit(0);
}
if(cnt == N) flag = true;
*/
/*
for(ll temp : C){
    if(M % temp == 0){
        cout << "-1\n";
        return 0;
    }
}
*/