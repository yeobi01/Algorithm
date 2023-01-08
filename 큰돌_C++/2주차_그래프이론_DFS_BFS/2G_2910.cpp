#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> mp, mp_first;
vector<pair<ll, ll>> v;
ll N, C;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        mp[temp]++;
        if(mp_first[temp] == 0) mp_first[temp] = i + 1; // if문 안에 0이니까 적어도 1이상 값을 가져야함.
    }
    for(auto t : mp){
        v.push_back({t.second, t.first});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto t : v){
        for(int i = 0; i < t.first; i++){
            cout << t.second << " ";
        }
    }
    cout << "\n";
    return 0;
}