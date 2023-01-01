#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        int x = 1;
        int cnt = 1;
        while(x % n != 0){
            x = x * 10 + 1;
            x %= n;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}
