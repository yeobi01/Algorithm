#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, ret;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        int a, t; tie(a, t) = v[i];
        if(ret < a) ret = a;
        ret += t;
    }
    cout << ret << "\n";
    return 0;
}