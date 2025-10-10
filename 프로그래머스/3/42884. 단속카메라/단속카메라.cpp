#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct car{
    int start;
    int end;
};

bool cmp(car x, car y){
    return x.end < y.end;
}

bool visited[10001];

int solution(vector<vector<int>> r) {
    
    vector<car> routes;
    for(vector<int> x : r){
        car temp;
        temp.start = x[0];
        temp.end = x[1];
        
        routes.push_back(temp);
    }
    
    sort(routes.begin(), routes.end(), cmp);
    
    int answer = 0;
    for(int i = 0; i < routes.size(); i++){
        if(visited[i]) continue;
        
        int end = routes[i].end;
        for(int j = i; j < routes.size(); j++){
            if(routes[j].start <= end){ 
                visited[j] = true;
            }
        }
        answer++;
    }
    
    return answer;
}