#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int N;
bool check[4000001];
vector<int> prime;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	fill(check, check + 4000000, true);
	for(int i = 2; i * i <= N; i++){
		if(check[i] == true){
			for(int j = i + i; j <= N; j += i) check[j] = false;
		}
	}

	for(int i = 2; i <= N; i++){
		if(check[i] == true) prime.push_back(i);
	}

	int cnt = 0, high = 0, low = 0, sum = 0;
	while(1){
		if(sum >= N){
			sum -= prime[low];
			low++;
		} else if(high == prime.size()) {
			break;
		} else{
			sum += prime[high];
			high++;
		}
		if(sum == N) cnt++;
	}
	cout << cnt << "\n";

    return 0;
}