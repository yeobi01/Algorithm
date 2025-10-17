from itertools import permutations 

def solution(k, dungeons):
    
    num_dungeons = len(dungeons)
    all_orders = permutations(dungeons, num_dungeons)
    
    counts = []
    for orders in all_orders:
        hp = k
        count = 0
        for dungeon in orders:
            if hp >= dungeon[0]:
                hp -= dungeon[1]
                count += 1
        counts.append(count)
        
    answer = max(counts)
    
    return answer