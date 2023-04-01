#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

ll A, B;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;
    for(ll i = A + 1; i <= 62; i++){
        ll temp = pow(2, i);
        while(temp > 9){ temp /= 10; }
        if(temp == B){
            cout << i << "\n";
            exit(0);
        }
    }
    cout << "0\n";
    return 0;
}