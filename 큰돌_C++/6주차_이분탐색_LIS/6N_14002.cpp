#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, arr[1004], temp[1004];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < N; i++){
        int lowerIdx = (lower_bound(v.begin(), v.end(), arr[i]) - v.begin());
        if(v.size() == lowerIdx) v.push_back(arr[i]);
        else v[lowerIdx] = arr[i];
        temp[i] = lowerIdx;
    }
    cout << v.size() << "\n";
    int len = v.size() - 1; stack<int> stk;
    for(int i = N - 1; i >= 0; i--){
        if(temp[i] == len){
            stk.push(arr[i]);
            len--;
        }
    }
    while(!stk.empty()){ cout << stk.top() << " "; stk.pop(); }
    return 0;
}