from queue import Queue

def make_map(rectangle, _map):
    for rec in rectangle:
        for i in range(rec[1] * 2, rec[3] * 2 + 1):
            for j in range(rec[0] * 2, rec[2] * 2 + 1):
                _map[i][j] = 1

def bfs(startX, startY, endX, endY, _map):
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    visited = [[False for _ in range(105)] for _ in range(105)]
    ret = 0
    
    q = Queue()
    q.put([startY * 2, startX * 2, 0])
    visited[startY * 2][startX * 2] = True
    while not q.empty():
        front = q.get()
        y = front[0]
        x = front[1]
        time = front[2]
        
        if y == endY * 2 and x == endX * 2:
            ret = time
            print(time)
            break;
        
        for d in range(4):
            ny = y + dy[d]
            nx = x + dx[d]
            if ny < 0 or nx < 0 or ny >= 105 or nx >= 105:
                continue
            if visited[ny][nx] or _map[ny][nx] == 0:
                continue
            if _map[ny - 1][nx - 1] and _map[ny - 1][nx + 1] and _map[ny + 1][nx - 1] and _map[ny + 1][nx + 1] and _map[ny][nx - 1] and _map[ny][nx + 1] and _map[ny + 1][nx] and _map[ny - 1][nx]:
                continue
            q.put([ny, nx, time + 1])
            visited[ny][nx] = True
    
    return ret / 2
    
def solution(rectangle, characterX, characterY, itemX, itemY):
    _map = [[0 for _ in range(105)] for _ in range(105)]
    make_map(rectangle, _map)
    answer = bfs(characterX, characterY, itemX, itemY, _map)
    return answer