#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, n;
string a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--){
        map<string, int> mp;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            mp[b]++;
        }

        ll ans = 1;
        for(auto x : mp){
            ans *= ((ll)x.second + 1);
        }

        cout << ans - 1 << "\n";
    }
    return 0;
}