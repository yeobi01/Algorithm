#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        int A[4], B[4];
        for(int i = 0; i < 4; i++) cin >> A[i];
        for(int i = 0; i < 4; i++) cin >> B[i];

        bool flag = false;
        for(int c1 = 1; c1 <= 10 && !flag; c1++){
            for(int c2 = 1; c2 <= 10 && !flag; c2++){
                for(int c3 = 1; c3 <= 10 && !flag; c3++){
                    bool ab = false, bc = false, ca = false;
                    for(int i = 0 ; i < 4; i++){
                        if(A[i] > max(c1, B[i])) ab = true;
                        if(B[i] > max(c2, A[i])) bc = true;
                        if(c3 > max(A[i], B[i])) ca = true;
                    }

                    
                }
            }
        }
    }

    return 0;
}