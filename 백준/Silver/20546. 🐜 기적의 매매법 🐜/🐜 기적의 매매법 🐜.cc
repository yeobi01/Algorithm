// 20546번. 🐜 기적의 매매법 🐜

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cash;
int bnp_cash, bnp_stock, bnp_total;
int timing_cash, timing_stock, timing_total;
vector<int> stock_price;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> cash;
    for(int i = 0; i < 14; i++){
        int temp; cin >> temp;
        stock_price.push_back(temp);
    }

    bnp_cash = cash;
    for(int i = 0; i < 14; i++){
        if(stock_price[i] <= bnp_cash){
            bnp_stock += bnp_cash / stock_price[i];
            bnp_cash %= stock_price[i];
        }
    }
    bnp_total = bnp_cash + bnp_stock * stock_price[13];

    int up = 1, down = 1;
    int flag = 0; // 0: start, 1: up, -1 down
    timing_cash = cash;
    for(int i = 1; i < 14; i++){
        if(up >= 3){
            timing_cash += timing_stock * stock_price[i];
            timing_stock = 0;
            // cout << timing_stock << " " << timing_cash << "\n";
        } else if(down >= 3){
            timing_stock += timing_cash / stock_price[i];
            timing_cash %= stock_price[i];
            // cout << timing_stock << " " << timing_cash << "\n";
        }
        // cout << "up: " << up << " down: " << down << "\n";

        if(stock_price[i - 1] < stock_price[i]){
            up++;
            down = 1;
            flag = 1;
        } else if(stock_price[i - 1] > stock_price[i]){
            down++;
            up = 1;
            flag = -1;
        }
    }
    timing_total = timing_cash + timing_stock * stock_price[13];

    // cout << bnp_total << "\n";
    // cout << timing_cash << " " << timing_stock << "\n";
    // cout << timing_total << "\n";

    if(bnp_total < timing_total) cout << "TIMING\n";
    else if(bnp_total > timing_total) cout << "BNP\n";
    else cout << "SAMESAME\n";

    return 0;
}