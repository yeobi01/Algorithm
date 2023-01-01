#include <bits/stdc++.h>
using namespace std;

int A, B, C, sum;
int cnt[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++){
        int in, out;
        cin >> in >> out;
        for(int j = in; j < out; j++){
            cnt[j]++;
        }
    }

    for(int i = 0; i < 100; i++){
        if(cnt[i] == 1){
            sum += A;
        } else if(cnt[i] == 2){
            sum += 2*B;
        } else if(cnt[i] == 3){
            sum += 3*C;
        }
    }

    cout << sum << "\n";
}