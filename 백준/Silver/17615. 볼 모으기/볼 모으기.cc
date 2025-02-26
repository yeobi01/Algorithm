// 0번. 문제 이름

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, R_count, B_count;
char RB[500000];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = n - 1; i >= 0; i--){
        cin >> RB[i];
        if(RB[i] == 'R') R_count++;
        if(RB[i] == 'B') B_count++;
    }
    
    char start_color = RB[0];
    for(int i = 0; i < n; i++){
        if(RB[i] != start_color) break;
        if(RB[i] == start_color && RB[i] == 'R') R_count--;
        if(RB[i] == start_color && RB[i] == 'B') B_count--;
    }

    int res = R_count < B_count ? R_count : B_count;
    cout << res << "\n";

    return 0;
}