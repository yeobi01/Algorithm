#include<bits/stdc++.h>
using namespace std;   
const int MAX = 987654321;

int N, S, arr[100001], ret = MAX;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;
    int temp = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int low = 1, high = 1, sum = arr[1];
    while(low <= high && high <= N){
        if(sum == S) ret = min(ret, (high - low + 1));
        if(sum < S){
            high++;
            sum += arr[high];
        } else{
            sum -= arr[low];
            low++;
        }
    }
    cout << ((ret == MAX) ? 0 : ret) << "\n";

    return 0;
}