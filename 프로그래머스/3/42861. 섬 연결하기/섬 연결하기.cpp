#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cost{
    int u;
    int v;
    int cost;
};

bool cmp(cost x, cost y){
    return x.cost < y.cost;
}

int parent[101];

int find(int u){
    if(parent[u] == u) return u;
    return find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}

vector<cost> graph;
vector<cost> mst;


void kruskal(int n){
    sort(graph.begin(), graph.end(), cmp);
    for(int i = 0; i < 101; i++) parent[i] = i;
    
    for(cost x : graph){
        if(find(x.u) == find(x.v)) continue;
        
        merge(x.u, x.v);
        mst.push_back(x);
        
        if(mst.size() == n - 1) break;
    }
}

int solution(int n, vector<vector<int>> costs) {
    
    for(vector<int> x : costs){
        cost temp;
        temp.u = x[0];
        temp.v = x[1];
        temp.cost = x[2];
        
        graph.push_back(temp);
    }
    
    kruskal(n);
    
    int answer = 0;
    for(cost x : mst){
        answer += x.cost;
    }
    
    return answer;
}