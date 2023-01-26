#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, ret, sum, low, high;
vector<int> prime;
bool che[4000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 2; i <= 4000000; i++){
        if(che[i]) continue;
        for(int j = 2 * i; j <= 4000000; j += i){
            che[j] = true;
        }
    }    
    
    cin >> N;
    for(int i = 2; i <= N; i++){
        if(!che[i]) prime.push_back(i);
    }
    while(1){
        if(sum >= N) sum -= prime[low++];
        else if(high == prime.size()) break;
        else sum += prime[high++];
        if(sum == N) ret++;
    }
    cout << ret << "\n";
    return 0;
}
