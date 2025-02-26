// 1758번. 알바생 강호

#include <bits/stdc++.h>
using namespace std;

long long n, res;
vector<int> v;

bool compare(long long x, long long y){
    return x > y;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < n; i++){
        res += (v[i] - i) > 0 ? (v[i] - i) : 0;
    }

    cout << res << "\n";

    return 0;
}