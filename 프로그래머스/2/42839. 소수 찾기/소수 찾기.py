from itertools import permutations

def get_prime_number_list():
    prime_number = [True] * 10000000 
    
    prime_number[0] = False
    prime_number[1] = False
    
    for i in range(2, int(10000000 ** 0.5) + 1):
        if prime_number[i]:
            for j in range(i * i, 10000000, i):
                prime_number[j] = False
                
    return prime_number
    
def solution(numbers):
    prime_numbers = get_prime_number_list()
    
    nums = [n for n in numbers]
    nums_set = set([])
    for i in range(1, len(nums) + 1):
        temp = list(permutations(nums, i))
        for num in temp:
            nums_set.add((int)(''.join(num)))
    
    answer = 0
    for num in nums_set:
        if prime_numbers[num]:
            answer += 1
    
    return answer