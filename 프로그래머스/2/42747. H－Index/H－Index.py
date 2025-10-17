def solution(citations):
    citations.sort()
    
    h = 0
    for i in range(len(citations)):        
        while h <= citations[i]:
            high_count = len(citations) - i
            if high_count >= h:
                answer = h
            h += 1
    
    return answer