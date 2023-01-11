#include<bits/stdc++.h>
using namespace std;   

int N, arr[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int diff = 2000000001;

    int low = 0, high = N - 1;
    int first, second;
    while(low < high){
        int now = arr[low] + arr[high];
        int _diff = abs(now);
        if(diff > _diff){
            diff = _diff;
            first = arr[low];
            second = arr[high];
        }
        if(now > 0) high--;
        else low++;
    }
    cout << first << " " << second << "\n";

    return 0;
}
