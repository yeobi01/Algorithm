#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, M, C, arr[2001], res = 0;
vector<pair<pair<int, int>, int>> v;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.first == b.first.first){
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> C;
    cin >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < M; i++){
        int from = v[i].first.first;
        int to = v[i].first.second;
        int box = v[i].second;
        int maxBox = 0;
        for(int j = from; j < to; j++){
            maxBox = max(maxBox, arr[j]);
        }
        int canBox = min(box, C - maxBox);
        for(int j = from; j < to; j++){
            arr[j] += canBox;
        }
        res += canBox;
    }
    cout << res << '\n';
    return 0;
}
