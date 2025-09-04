#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct playlist_data{
    int total_plays;
    int first_id;
    int first_plays;
    int second_id;
    int second_plays;
    int music_count;
};

unordered_map<string, playlist_data> playlist_map;
vector<playlist_data> playlist_vec;

bool cmp(playlist_data a, playlist_data b){
    return a.total_plays > b.total_plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int len = genres.size();
    
    for(int i = 0; i < len; i++){
        playlist_map[genres[i]].total_plays += plays[i];
        playlist_map[genres[i]].music_count++;
        if(playlist_map[genres[i]].first_plays < plays[i]){
            playlist_map[genres[i]].second_id = playlist_map[genres[i]].first_id;
            playlist_map[genres[i]].second_plays = playlist_map[genres[i]].first_plays;
            playlist_map[genres[i]].first_id = i;
            playlist_map[genres[i]].first_plays = plays[i];
        } else if(playlist_map[genres[i]].second_plays < plays[i]){
            playlist_map[genres[i]].second_id = i;
            playlist_map[genres[i]].second_plays = plays[i];
        }
    }
    for(auto x : playlist_map){
        playlist_vec.push_back(x.second);
    }
    
    sort(playlist_vec.begin(), playlist_vec.end(), cmp);
    
    vector<int> answer;
    for(auto x : playlist_vec){
        if(x.first_plays > 0) answer.push_back(x.first_id);
        if(x.second_plays > 0) answer.push_back(x.second_id);
    }

    return answer;
}

/*

장르 map으로 
map <string, int, greater> map1;  key 내림차순 ..




*/