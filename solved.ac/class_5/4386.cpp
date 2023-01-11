#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int parent[101], N;
float star[101][2];
vector<pair<pair<int, int>, float>> edge;


int getParent(int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x < y) parent[y] = x;
	else parent[x] = y;
}

bool findParent(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x == y) return true;
	else return false;
}

bool cmp(pair<pair<int,int>, float> a, pair<pair<int,int>, float> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 1; i <= N; i++) parent[i] = i;
	for(int i = 0; i < N; i++){
		cin >> star[i][0] >> star[i][1];
	}
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			float d = sqrt(pow((star[i][0] - star[j][0]), 2) + pow((star[i][1] - star[j][1]), 2));
			edge.push_back({{i, j}, d});
		}
	}
	float d = sqrt(pow((star[0][0] - star[N - 1][0]), 2) + pow((star[0][1] - star[N - 1][1]), 2));
	edge.push_back({{0, N - 1}, d});

	sort(edge.begin(), edge.end(), cmp);

	float ret = 0;
	for(pair<pair<int,int>, float> p : edge){
		if(!findParent(p.first.first, p.first.second)){
			ret += p.second;
			unionParent(p.first.first, p.first.second);
		}
	}

	printf("%.2f\n", ret);

    return 0;
} // 크루스칼 알고리즘