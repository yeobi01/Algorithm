answer = 0

def dfs(sum, index, numbers, target):
    global answer
    
    if index == len(numbers):
        if sum == target:
            answer += 1
        return
    
    dfs(sum + numbers[index], index + 1, numbers, target)
    dfs(sum - numbers[index], index + 1, numbers, target)

    return
    
def solution(numbers, target):
    global answer
    
    dfs(0, 0, numbers, target)
    
    return answer