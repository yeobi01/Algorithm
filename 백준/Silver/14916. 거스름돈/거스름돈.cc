// 14916번. 거스름돈

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, res;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    while(n % 5 != 0){
        n -= 2;
        res++;
    }
    res += n / 5;

    if(n < 0) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}