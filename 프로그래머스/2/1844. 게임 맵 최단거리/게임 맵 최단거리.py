from queue import Queue

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def solution(maps):
    answer = -1
    
    n = len(maps) # 세로
    m = len(maps[0]) # 가로
    
    visited = [[False for _ in range(m)] for _ in range(n)]
    
    q = Queue()
    q.put([0, 0, 1])
    visited[0][0] = True
    while not q.empty():
        current = q.get()
        y = current[0]
        x = current[1]
        time = current[2]
        
        if y == n - 1 and x == m - 1:
            answer = time
            break
        
        for d in range(4):
            ny = y + dy[d]
            nx = x + dx[d]
            if ny < 0 or nx < 0 or ny >= n or nx >= m:
                continue
            if visited[ny][nx] or maps[ny][nx] == 0:
                continue
            q.put([ny, nx, time + 1])
            visited[ny][nx] = True        

    return answer