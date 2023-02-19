#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

int T, N, M;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        v.clear();

        cin >> N;
        for(int i = 0; i < N; i++){
            int temp; cin >> temp;
            v.push_back(temp);
        } sort(v.begin(), v.end());
        cin >> M;
        for(int i = 0; i < M; i++){
            int temp; cin >> temp;
            int low = 0, high = N - 1, mid; bool flag = false;
            while(low <= high){
                mid = (low + high) / 2;
                if(v[mid] == temp){
                    flag = true;
                    break;
                } else if(v[mid] > temp){
                    high = mid - 1;
                } else if(v[mid] < temp){
                    low = mid + 1;
                }
            }
            flag ? cout << "1\n" : cout << "0\n";
        }
    }

    return 0;
}