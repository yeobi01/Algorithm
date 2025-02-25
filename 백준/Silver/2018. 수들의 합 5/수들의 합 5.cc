#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        int temp = n - i*(i - 1) / 2;
        if(temp <= 0) break;
        if(temp % i == 0) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}