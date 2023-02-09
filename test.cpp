int cnt[30][3001] = {0, }, len;

int go(int idx, int idx_target, string target){
    if(idx_target >= target.length()){
        return 1;    
    }
    
    char find = target[idx_target];
    int sum = 0;
    for(int i = idx; i < len; i++){
        int temp = 0;
        if(cnt[(int)(find - 'a')][i]){
            //cout << idx_target << " " << i << "\n"; 
            temp = cnt[(int)(find - 'a')][i];
            temp *= go(i + 1, idx_target + 1, target);
        }
        sum += temp;
    }
    return sum;
}

int numWays(vector<string> words, string target) {
    len = words[0].length();
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < len; j++){
            for(string tmp : words){            
                if((char)('a' + i) == tmp[j]){
                    cnt[i][j]++;
                }
            }
        }
    }
    int ret = go(0, 0, target);
    return ret;
}