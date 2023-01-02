#include <bits/stdc++.h>
using namespace std;

int N, M, J, head, tail, ret;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> J;
    for(int i = 0; i < J; i++){
        int temp; cin >> temp;
        q.push(temp); 
    }

    head = 1; tail = M;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x >= head && x <= tail) continue;
        else if(x < head){
            ret += head - x;
            head = x; tail = x + M - 1;
        } else if(x > tail){
            ret += x - tail;
            tail = x; head = tail - M + 1;
        }
    }

    cout << ret << "\n";
    return 0;
}