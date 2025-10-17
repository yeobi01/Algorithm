def solution(sizes):
    big_length = []
    small_length = []
    
    for size in sizes:
        if size[0] >= size[1]:
            big_length.append(size[0])
            small_length.append(size[1])
        else:
            big_length.append(size[1])
            small_length.append(size[0])
    
    big_max = max(big_length)
    small_max = max(small_length)
    
    answer = big_max * small_max
    
    return answer