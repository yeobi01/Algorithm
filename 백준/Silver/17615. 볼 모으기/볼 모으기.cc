// 0번. 문제 이름

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, Rr_count, Br_count, Rl_count, Bl_count;
char RB[500000];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = n - 1; i >= 0; i--){
        cin >> RB[i];
        if(RB[i] == 'R') Rr_count++;
        if(RB[i] == 'B') Br_count++;
    }
    Rl_count = Rr_count;
    Bl_count = Br_count;
    
    char start_color = RB[0];
    for(int i = 0; i < n; i++){
        if(RB[i] != start_color) break;
        if(RB[i] == start_color && RB[i] == 'R') Rr_count--;
        if(RB[i] == start_color && RB[i] == 'B') Br_count--;
    }
    char end_color = RB[n - 1];
    for(int i = n - 1; i >= 0; i--){
        if(RB[i] != end_color) break;
        if(RB[i] == end_color && RB[i] == 'R') Rl_count--;
        if(RB[i] == end_color && RB[i] == 'B') Bl_count--;
    }

    int r_min = Rr_count < Br_count ? Rr_count : Br_count;
    int l_min = Rl_count < Bl_count ? Rl_count : Bl_count;
    int res = r_min < l_min ? r_min : l_min;
    cout << res << "\n";

    return 0;
}