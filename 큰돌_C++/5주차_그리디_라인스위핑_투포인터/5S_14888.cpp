#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, a[12], b[4];
int _max = -INF, _min = INF;

void go(int idx, int cur, int plus, int minus, int mul, int div){
    if(idx == N - 1){
        _max = max(cur, _max);
        _min = min(cur, _min);
        return;
    }
    if(plus) go(idx + 1, cur + a[idx + 1], plus - 1, minus, mul, div);
    if(minus) go(idx + 1, cur - a[idx + 1], plus, minus - 1, mul, div);
    if(mul) go(idx + 1, cur * a[idx + 1], plus, minus, mul - 1, div);
    if(div) go(idx + 1, cur / a[idx + 1], plus, minus, mul, div - 1);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> b[i];

    go(0, a[0], b[0], b[1], b[2], b[3]);
    cout << _max << "\n" << _min << "\n";
    return 0;
}