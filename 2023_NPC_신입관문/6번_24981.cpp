#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int N, ret = INF;
vector<int> l, g;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        char c; int temp; cin >> c >> temp;
        if(c == 'L') l.push_back(temp);
        if(c == 'G') g.push_back(temp);
    }
    sort(l.begin(), l.end());
    sort(g.begin(), g.end());
    for(int i = 0; i < l.size(); i++){
        int idx = lower_bound(g.begin(), g.end(), l[i]) - g.begin();
        int temp = i + (g.size() - idx);
        ret = min(ret, temp);
    }
    for(int i = 0; i < g.size(); i++){
        int idx = lower_bound(l.begin(), l.end(), g[i]) - l.begin();
        int temp = idx + (g.size() - i - 1);
        ret = min(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}
/*
10
G 3
L 7
G 10
L 1
L 4
G 8
L 13
G 11
G 4
L 2
*/