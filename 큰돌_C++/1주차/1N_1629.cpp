#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, C;

ll pow(ll a, ll n){
    if(n == 1){
        return a % C;
    }

    if(n & 1){
        return (pow(a, n/2)*pow(a, n/2 + 1))%C;
    } else{
        return (pow(a, n/2)*pow(a, n/2)%C);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << pow(A, B) << "\n";

    return 0;
}