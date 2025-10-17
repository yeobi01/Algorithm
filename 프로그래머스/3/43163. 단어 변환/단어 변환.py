from queue import Queue

def is_diff_only_one(current, next_word):
    diff_count = 0
    for i in range(len(current)):
        if current[i] != next_word[i]:
            diff_count += 1
    if diff_count == 1:
        return True
    return False

def solution(begin, target, words):
    answer = 0
    
    visited = [False for _ in range(len(words))]
    q = Queue()
    q.put((begin, 0))
    while not q.empty():
        current = q.get()
        current_word = current[0]
        time = current[1]
        
        if current_word == target:
            answer = time
            break
        
        for i in range(len(words)):
            if visited[i]:
                continue
            if not is_diff_only_one(current_word, words[i]):
                continue
            q.put((words[i], time + 1))
            visited[i] = True        
    
    return answer