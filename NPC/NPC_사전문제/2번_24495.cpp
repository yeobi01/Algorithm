#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int T;

void go(int& a, int& b, int A[4], int B[4]){
    int cnt_a = 0, cnt_b = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(A[i] > B[j]) cnt_a++;
            else if(A[i] < B[j]) cnt_b++;
        }
    }
    if(cnt_a > cnt_b){ a++; b--; }
    else if(cnt_b > cnt_a){ b++; a--; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        int A[4], B[4], C[4];
        for(int i = 0; i < 4; i++) cin >> A[i];
        for(int i = 0; i < 4; i++) cin >> B[i];
        
        bool flag = false;
        for(int c0 = 1; c0 <= 10 && !flag; c0++){
            C[0] = c0;
            for(int c1 = 1; c1 <= 10 && !flag; c1++){
                C[1] = c1;
                for(int c2 = 1; c2 <= 10 && !flag; c2++){
                    C[2] = c2;
                    for(int c3 = 1; c3 <= 10 && !flag; c3++){
                        C[3] = c3;

                        int a = 0, b = 0, c = 0;
                        go(a, b, A, B);
                        go(b, c, B, C);
                        go(c, a, C, A);
                        if(a == 0 && b == 0 && c == 0){
                            cout << "yes\n";
                            flag = true;
                        }
                    }
                }
            }
        }
        if(!flag) cout << "no\n";
    }

    return 0;
}