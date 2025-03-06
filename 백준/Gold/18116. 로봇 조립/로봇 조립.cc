// 18116번. 로봇 조립

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int parent[1000001];
int cnt[1000001];
int ranking[1000001];

void make_single_node(int x){
    parent[x] = x;
    cnt[x] = 1;
    ranking[x] = 1;
    return ;
}

int get_parent(int x){
    if(x == parent[x]) return x;
    return get_parent(parent[x]);
}

void input_I(int a, int b){
    if(parent[a] == 0) make_single_node(a);
    if(parent[b] == 0) make_single_node(b);

    a = get_parent(a);
    b = get_parent(b);
    if(a == b) return ;
    if(ranking[a] > ranking[b]) swap(a, b);
    parent[a] = b;
    if(ranking[a] == ranking[b]) ranking[b]++;
    cnt[b] += cnt[a];
    cnt[a] = 0;
}

void input_Q(int c){
    if(parent[c] == 0) make_single_node(c);

    c = get_parent(c);
    cout << cnt[c] << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch;
        if(ch == 'I'){
            int a, b; cin >> a >> b;
            input_I(a, b);
        } else if(ch == 'Q'){
            int c; cin >> c;
            input_Q(c);
        }
    }

    return 0;
}