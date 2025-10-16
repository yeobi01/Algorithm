from queue import Queue

graph = [[] for _ in range(20001)]

def solution(n, edge):
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    
    distances = [-1] * (n + 1)
    
    q = Queue()
    q.put(1)
    distances[1] = 0
    while not q.empty():
        node = q.get()
        
        for neighbor in graph[node]:
            if distances[neighbor] != -1:
                continue
            
            q.put(neighbor)
            distances[neighbor] = distances[node] + 1

    max_distance = max(distances)
    answer = distances.count(max_distance)
            
    return answer