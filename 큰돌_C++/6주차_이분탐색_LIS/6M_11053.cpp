#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, temp;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        int lowerIdx = (lower_bound(v.begin(), v.end(), temp) - v.begin());
        if(v.size() == lowerIdx) v.push_back(temp);
        else v[lowerIdx] = temp;
    }
    cout << v.size() << "\n";
    return 0;
}
/*
int N, temp, lis[1004], len;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        int lowerIdx = lower_bound(lis, lis + len, temp) - lis;
        cout << i << " " << len << " " << lowerIdx << "\n";
        if(lis[lowerIdx] == 0) len++;
        lis[lowerIdx] = temp;
    }
    cout << len << "\n";
    return 0;
}
*/