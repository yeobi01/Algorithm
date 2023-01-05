#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1501;

int K, tree_length, arr[2000];
vector<int> ret[14];

void go(int head, int tail, int level){
    if(head > tail) return;
    if(head == tail){
        ret[level].push_back(arr[head]);
        return;
    }
    int mid = (head + tail) / 2;
    ret[level].push_back(arr[mid]);
    go(head, mid - 1, level + 1);
    go(mid + 1, tail, level + 1);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K; tree_length = pow(2, K) - 1;
    for(int i = 0; i < tree_length; i++){
        cin >> arr[i];
    }

    go(0, tree_length, 1);

    for(int i = 1; i <= K; i++){
        for(int j : ret[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}