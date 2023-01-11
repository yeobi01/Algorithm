#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int parent[10000], N, M;
vector<pair<pair<int,int>, int>> edge;

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

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 1; i <= N; i++) parent[i] = i;


	int a, b, c;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		edge.push_back({{a, b}, c});
	}

	sort(edge.begin(), edge.end(), cmp);

	int ret = 0;
	for(pair<pair<int,int>, int> p : edge){
		if(!findParent(p.first.first, p.first.second)){
			ret += p.second;
			unionParent(p.first.first, p.first.second);
		}
	}

	cout << ret << "\n";

    return 0;
} // 크루스칼 알고리즘