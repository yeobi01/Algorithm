alpabet = ['A', 'E', 'I', 'O', 'U']

count = 0
is_find = False

def dfs(s, word):
    global count, is_find
    
    count += 1
    
    if s == word:
        is_find = True
        return
    if len(s) == 5:
        return

    for a in alpabet:
        if is_find:
            break
        dfs(s + a, word)
        
    return
        

def solution(word):    
    dfs("", word)
    return (count - 1)