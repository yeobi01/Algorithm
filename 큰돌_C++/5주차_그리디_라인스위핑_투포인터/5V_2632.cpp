#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int want, n, m, temp, cnt;
int a[1001], b[1001], ret, aSum, bSum, psum_a[2002], psum_b[2002];
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int> &_map){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n + i - 1; j++){
            int sum = psum[j] - psum[j - i];
            _map[sum]++;
            if(i == n) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> want;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum_a[i] = psum_a[i - 1]+ a[i];
    }
    for(int i = n + 1; i <= 2 * n; i++){
        psum_a[i] = psum_a[i - 1] + a[i - n];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }
    for(int i = m + 1; i <= 2 * m; i++){
        psum_b[i] = psum_b[i - 1] + b[i - m];
    }

    make(n, psum_a, aCnt);
    make(m, psum_b, bCnt);

    int sum = 0;
    for(int i = 1; i < want; i++){
        sum += aCnt[want - i] * bCnt[i];
    }
    sum += aCnt[want];
    sum += bCnt[want];

    cout << sum << "\n";
    return 0;
}