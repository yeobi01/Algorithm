#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int T, N, M;
vector<int> a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        int ret = 0, temp;
        a.clear(); b.clear();

        cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> temp, a.push_back(temp);
        for(int i = 0; i < M; i++) cin >> temp, b.push_back(temp);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        for(int x : a){
            if(x <= b[0]) continue;

            int low = 0, high = M - 1, mid, temp;
            while(low <= high){
                mid = (low + high) / 2;
                if(x > b[mid]){
                    temp = mid;
                    low = mid + 1;
                } else{
                    high = mid - 1;
                }
            }
            ret += (temp + 1);
        }
        cout << ret << "\n";
    }
    return 0;
}