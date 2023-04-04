#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll W, H, L1, L2, ret;

int gcd(int a, int b){
    if(a < b){ swap(a, b); }
    while(1){
        int r = a % b;
        if(r == 0) return b;

        a = b;
        b = r;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> H >> L1 >> L2;
    if(L1 == 1){
        ret += (W + 1) * H + W * (H + 1);
    }
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= H; j++){
            if(gcd(i, j) == 1){
                int len = i*i + j*j;
                if(L1*L1 <= len && len <= L2*L2){
                    ret += (W - i + 1) * (H - j + 1) * 2;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}