def solution(answers):
    answer_1 = [1, 2, 3, 4, 5]
    answer_1_size = len(answer_1)
    answer_2 = [2, 1, 2, 3, 2, 4, 2, 5]
    answer_2_size = len(answer_2)
    answer_3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    answer_3_size = len(answer_3)    
    
    count = [0, 0, 0, 0]
    for i in range(len(answers)):
        if answers[i] == answer_1[i % answer_1_size]:
            count[1] += 1
        if answers[i] == answer_2[i % answer_2_size]:
            count[2] += 1
        if answers[i] == answer_3[i % answer_3_size]:
            count[3] += 1
    
    count_max = max(count)
    answer = []
    for i in range(1, 4):
        if count_max == count[i]:
            answer.append(i)
    
    return answer