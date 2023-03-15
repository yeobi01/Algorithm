#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int N, a[100001], b[100001], idx_a[100001], ret;
bool moved[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) { cin >> a[i]; idx_a[a[i]] = i; }
    for(int i = 0; i < N; i++) cin >> b[i];

    int pa = 0;
    for(int i = 0; i < N; i++){
        while(moved[pa]) pa++;
        if(b[i] == a[pa]){
            pa++;
        } else{
            moved[idx_a[b[i]]] = true;
            ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}