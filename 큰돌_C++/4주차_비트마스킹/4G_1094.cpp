#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;

int X, ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> X;
    for(int i = 0; i < 32; i++){
        if(X & (1 << i)) ret++;
    }
    cout << ret << "\n";
    return 0;
}