#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll N, Nopt, F, M, ret, memo[200001], min_C = INF;
bool FN[40001], flag = false;
vector<ll> C;

ll go(ll cnt, ll eat){
    if(cnt < min_C){
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
            ll temp = cnt - C_i;
            while(FN[temp]){
                temp += M;
            }
            ans = max(ans, go(temp, eat + C_i));
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cin.tie(0)->sync_with_stdio(0);

    memset(memo, -1, sizeof(memo));

    cin >> N >> Nopt >> F >> M;
    for(int i = 0; i < Nopt; i++){
        ll temp; cin >> temp;
        C.push_back(temp);
        min_C = min(min_C, temp);
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
10 1 2 1
2 
8
9
*/
/*
if(cnt == 0){
    return eat;
}
*/
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