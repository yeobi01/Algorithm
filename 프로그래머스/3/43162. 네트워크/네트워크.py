from queue import Queue

def bfs(start, visited, n, graph):
    q = Queue()
    q.put(start)
    visited[start] = True
    while not q.empty():
        node = q.get()
        
        for next_node in range(n):
            if visited[next_node]:
                continue
            if graph[node][next_node] == 0:
                continue
            
            q.put(next_node)
            visited[next_node] = True
        
    
def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]
    for node in range(n):
        if visited[node]:
            continue
        answer += 1
        bfs(node, visited, n, computers)
    
    return answer