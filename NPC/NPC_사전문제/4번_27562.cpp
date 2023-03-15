#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

struct Cow{
    int s, t, c;
};
struct Aircon{
    int a, b, p, m;
};

int N, M, ret = INF;
Cow cow[21];
Aircon air[11];

void check(int visited){
    int sum[101] = {0, }, temp_money = 0;
    for(int i = 0; i < M; i++){
        if(visited & (1 << i)){
            temp_money += air[i].m;
            for(int j = air[i].a; j <= air[i].b; j++){
                sum[j] += air[i].p;
            } 
        }
    }
    bool flag = true;
    for(int i = 0; i < N && flag; i++){
        for(int j = cow[i].s; j <= cow[i].t && flag; j++){
            if(sum[j] < cow[i].c) flag = false;
        }
    }
    if(flag) ret = min(ret, temp_money);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int s, t, c; cin >> s >> t >> c;
        cow[i] = {s, t, c};
    }
    for(int i = 0; i < M; i++){
        int a, b, p, m; cin >> a >> b >> p >> m;
        air[i] = {a, b, p, m};
    }

    for(int i = 0; i < pow(2, M); i++) check(i);

    cout << ret << "\n"; 

    return 0;
}

/*
struct Cow{
    int s, t, c;
};
struct Aircon{
    int a, b, p, m;
};

int N, M, ret = INF, visited[11];
Cow cow[21];
Aircon air[11];

void check(){
    int sum[101] = {0, }, temp_money = 0;
    for(int i = 0; i < M; i++){
        if(visited[i]){
            temp_money += air[i].m;
            for(int j = air[i].a; j <= air[i].b; j++){
                sum[j] += air[i].p;
            } 
        }
    }
    bool flag = true;
    for(int i = 0; i < N && flag; i++){
        for(int j = cow[i].s; j <= cow[i].t && flag; j++){
            if(sum[j] < cow[i].c) flag = false;
        }
    }
    if(flag) ret = min(ret, temp_money);
    return;
}

void go(int pos){
    if(pos == M){
        check();
        return;
    }

    visited[pos] = true;
    go(pos + 1);
    visited[pos] = false;
    go(pos + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int s, t, c; cin >> s >> t >> c;
        cow[i] = {s, t, c};
    }
    for(int i = 0; i < M; i++){
        int a, b, p, m; cin >> a >> b >> p >> m;
        air[i] = {a, b, p, m};
    }

    go(0);
    cout << ret << "\n"; 

    return 0;
}*/