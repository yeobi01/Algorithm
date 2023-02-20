#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

ll X, Y, Z;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;
    Z = (100 * Y) / X;

    ll low = 0, high = INF, mid, ret = -1;
    while(low <= high){
        mid = (low + high) / 2;
        ll nZ = (100 * (Y + mid)) / (X + mid);
        if(Z != nZ){
            ret = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}