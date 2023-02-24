#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, temp, lis[1004], len;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        int lowerIdx = lower_bound(lis, lis + len, temp) - lis;
        if(lis[lowerIdx] == 0) len++;
        lis[lowerIdx] = temp;
    }
    cout << len << "\n";
    return 0;
}