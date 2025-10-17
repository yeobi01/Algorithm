def solution(brown, yellow):
    answer = []
    
    x = (int)(((brown / 2 + 2) + ((brown / 2 + 2) ** 2 - 4 * (brown + yellow)) ** 0.5) / 2)
    y =  (int)(((brown / 2 + 2) - ((brown / 2 + 2) ** 2 - 4 * (brown + yellow)) ** 0.5) / 2)   
    
    answer = [x, y]
    
    return answer
