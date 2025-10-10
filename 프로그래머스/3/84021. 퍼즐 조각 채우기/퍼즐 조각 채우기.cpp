#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos{
    int y;
    int x;
    

};

bool cmp(pos x, pos y){
    if(x.y == y.y){
        return x.x < y.x;
    }
    return x.y < y.y;
}

bool operator==(const pos& a, const pos& b) {
    // y좌표와 x좌표가 모두 같으면 true를 반환
    return a.y == b.y && a.x == b.x;
}

int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

void normalization(vector<pos> &vec){
    sort(vec.begin(), vec.end(), cmp);
    
    int origin_y = vec[0].y;
    int origin_x = vec[0].x;
    
    for(pos &p : vec){
        p.y -= origin_y;
        p.x -= origin_x;
    }
}

void rotate_90(vector<pos> &vec){
    for(pos &p : vec){
        int origin_y = p.y;
        int origin_x = p.x;
        
        p.y = origin_x;
        p.x = -1 * origin_y;
    }
    
    normalization(vec);
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    vector<vector<pos>> game_board_shape;
    for(int i = 0; i < game_board.size(); i++){
        for(int j = 0; j < game_board[i].size(); j++){
            if(game_board[i][j]) continue;
            
            vector<pos> temp;
            queue<pos> q;
            game_board[i][j] = 1;
            q.push({i, j});
            temp.push_back({i, j});
            while(!q.empty()){
                pos cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= game_board.size() || nx >= game_board[i].size()) continue;
                    if(game_board[ny][nx]) continue;
                    
                    game_board[ny][nx] = 1;
                    q.push({ny, nx});
                    temp.push_back({ny, nx});
                }
            }
            
            game_board_shape.push_back(temp);
        }
    }
    
    cout << "game_board_shape\n";
    for(vector<pos> x : game_board_shape){
        for(pos y : x){
            cout << y.y << " " << y.x << " | ";
        }
        cout << "\n";
    }
    
    vector<vector<pos>> table_shape;
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[i].size(); j++){
            if(!table[i][j]) continue;
            
            vector<pos> temp;
            queue<pos> q;
            table[i][j] = 0;
            q.push({i, j});
            temp.push_back({i, j});
            while(!q.empty()){
                pos cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= game_board.size() || nx >= game_board[i].size()) continue;
                    if(!table[ny][nx]) continue;
                    
                    table[ny][nx] = 0;
                    q.push({ny, nx});
                    temp.push_back({ny, nx});
                }
            }
            
            table_shape.push_back(temp);
        }
    }
    
    cout << "table_shape\n";
    for(vector<pos> x : table_shape){
        for(pos y : x){
            cout << y.y << " " << y.x << " | ";
        }
        cout << "\n";
    }
    
    cout << "normalization game_board_shape\n";
    for(vector<pos> &x : game_board_shape){
        normalization(x);
        for(pos y : x){
            cout << y.y << " " << y.x << " | ";
        }
        cout << "\n";
    }
    cout << "normalization table_shape\n";
    for(vector<pos> &x : table_shape){
        normalization(x);
        for(pos y : x){
            cout << y.y << " " << y.x << " | ";
        }
        cout << "\n";
    }
    
    // vector<bool> visited_game(game_board_shape.size(), false);
    
    int answer = 0;
    vector<bool> visited_table(table_shape.size(), false);
    for(vector<pos> &a : game_board_shape){
        bool flag = true;
        for(int i = 0; i < table_shape.size() && flag; i++){
            if(visited_table[i]) continue;
            for(int d = 0; d < 4; d++){
                if(a == table_shape[i]){
                    answer += table_shape[i].size();
                    visited_table[i] = true;
                    // cout << "i: " << i << " ";
                    flag = false;
                    break;
                } 
                rotate_90(table_shape[i]);
            }
        }
    }
    
    return answer;
}