from queue import Queue

def bfs(start, visited, graph):
    ret = 1
    
    q = Queue()
    q.put(start)
    visited[start] = True
    while not q.empty():
        node = q.get()
        for next_node in graph[node]:
            if visited[next_node]:
                continue
            q.put(next_node)
            visited[next_node] = True
            ret += 1
    
    return ret

def solution(n, wires):
    answer = []
    
    for unlink_wire_index in range(len(wires)):
        graph = [[] for _ in range(n + 1)]
        for i in range(len(wires)):
            if i == unlink_wire_index:
                continue
            graph[wires[i][0]].append(wires[i][1])
            graph[wires[i][1]].append(wires[i][0])
        
        visited = [False for _ in range(n + 1)]
        linked_tower_count = []
        for node in range(1, n + 1):
            if visited[node]:
                continue
            count = bfs(node, visited, graph)
            linked_tower_count.append(count)
        
        answer.append(abs(linked_tower_count[0] - linked_tower_count[1]))
    
    return min(answer)