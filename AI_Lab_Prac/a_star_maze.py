import heapq

def astar(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    h=lambda x: abs(x[0]-goal[0])+abs(x[1]-goal[1])
    q=[(h(start),0,start,[start])]
    d={start:0}

    while q:
        f, cost, cur, path = heapq.heappop(q)

        if cur==goal:
            return path, cost

        if cost>d[cur]:
            continue

        for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            v=(cur[0]+dr, cur[1]+dc)

            if not (0<=v[0]<rows and 0<=v[1]<cols) or grid[v[0]][v[1]]=='#':
                continue

            new_cost=cost+1

            if new_cost<d.get(v, float('inf')):
                d[v]=new_cost
                heapq.heappush(q, (new_cost+h(v), new_cost, v, path+[v]))

    return None, float('inf')

print("Enter maze rows (. = open, # = wall, S = start, G = goal), empty line to finish:")
grid=[]
while True:
    line=input().strip()
    if not line: break
    grid.append(line)

start = next((r,c) for r,row in enumerate(grid) for c,x in enumerate(row) if x == 'S')
goal  = next((r,c) for r,row in enumerate(grid) for c,x in enumerate(row) if x == 'G')

path, cost = astar(grid, start, goal)

print("Path:", path)
print("Cost:", cost)