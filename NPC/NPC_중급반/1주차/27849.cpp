#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll N, T, sum, ret;
ll db[100001][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> db[i][0] >> db[i][1];
    }

    for(int i = 0; i < N - 1; i++){
        if((db[i + 1][0] - db[i][0]) < (db[i][1] + sum)){
            ret += db[i + 1][0] - db[i][0];
            sum += db[i][1] - (db[i + 1][0] - db[i][0]);
        } else{
            ret += (db[i][1] + sum);
            sum = 0;
        }
    }
    if((T - db[N - 1][0]) < (db[N - 1][1] + sum)){
        ret += (T - db[N - 1][0] + 1);
    } else{
        ret += (db[N - 1][1] + sum);
    }

    cout << ret << "\n";
    return 0;
} 

/*
int main(){
    ll n, t, hay, saving = 0, prev, cur, ans = 0;
	cin >> n >> t;
	cin >> cur >> hay;
	saving += hay;
	n--;
	while (n--){
	    prev = cur;
	    cin >> cur >> hay;
	    ll eat = min(saving, cur - prev);
	    ans += eat;
	    saving -= eat;
	    saving += hay;
	}
	ll eat = min(saving, t+1 - cur);
	ans += eat;
	
	cout << ans;
	return 0;
}
*/