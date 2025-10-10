#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(string name) {
    int start_A = -1, end_A = -1;
    int max_A_length = 0;
    int cur_A_length = 0;
    if(name[0] == 'A') cur_A_length = 1;
    for(int i = 1; i < name.length(); i++){
        if(name[i] == 'A' && name[i - 1] == 'A') {
            cur_A_length++;
            if(max_A_length < cur_A_length){
                max_A_length = cur_A_length;
                end_A = i;
                start_A = end_A - max_A_length + 1;
            }
        }
        else if(name[i] == 'A') {
            cur_A_length = 1;
            if(max_A_length < cur_A_length){
                max_A_length = cur_A_length;
                end_A = i;
                start_A = end_A - max_A_length + 1;
            }
        }
        else if(name[i] != 'A' && cur_A_length > 0){
            cur_A_length = 0;
        }
    }

    cout << max_A_length << "\n";
    cout << start_A << " " << end_A << "\n";
    
    int cursor_case_1 = name.length() - 1;
    while(name[cursor_case_1] == 'A') cursor_case_1--;
    if(cursor_case_1 < 0) cursor_case_1 = 0;

    int cursor_case_2 = (start_A - 1) * 2 + 1 + (name.length() - end_A - 2);
    int cursor_case_3 = 1 + (name.length() - end_A - 2) * 2 + 1 + (start_A - 1);
    
    int cursor_min = 987654321;
    cursor_min = cursor_case_1 < cursor_case_2 ? cursor_case_1 : cursor_case_2;
    cursor_min = cursor_min < cursor_case_3 ? cursor_min : cursor_case_3;
    
    cout << cursor_min << endl;
    cout << cursor_case_1 << " " << cursor_case_2 << " " << cursor_case_3 << endl;
    
    if(start_A == -1 && end_A == -1) cursor_min = cursor_case_1;
    
    int answer = cursor_min;
    if(answer < 0) answer = 0;
    
    for(int i = 0; i < name.length(); i++){
        int case_1 = abs((int)(name[i] - 'A'));
        int case_2 = abs((int)('Z' - name[i])) + 1;
        int _min = case_1 < case_2 ? case_1 : case_2;
        
        answer += _min;
    }
    
    return answer;
}

/*
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
a b c d e f g h i j k l m n o p q r s t u v w x y z

J
1번으로 A

그냥 왼쪽 오른쪽 움직이기
가장 왼쪽에서 해당 문자까지 가기
가장 오른쪽에서 해당 문자까지 가기

*/