maze=[
    [0,0,0,0,1,1,1,0,1],
    [0,1,1,1,1,1,1,0,1],
    [0,0,0,0,0,0,0,0,1],
    [0,1,1,1,1,1,1,1,1],
    [0,0,0,1,0,0,0,0,1],
    [0,1,0,1,0,0,0,1,1],
    [0,1,0,1,1,1,0,1,0],
    [0,0,0,0,0,0,0,1,0],
    [1,1,1,1,1,1,0,0,0]
]

mves=[(-1,0),(1,0),(0,-1),(0,1)]

vis=[[False for _ in range(len(maze[0]))] for _ in range(len(maze))]

par=[[None for _ in range(len(maze[0]))] for _ in range(len(maze))]

def is_val(maze, vis, r, c):
    rs, cs = len(maze), len(maze[0])
    return (0<=r<rs and 0<=c<cs and maze[r][c]==0 and not vis[r][c])

def dfs(maze, vis, r, c, gr, gc):
    if r==gr and c==gc:
        return True
    vis[r][c]=True
    for dr, dc in mves:
        nr, nc= r+dr, c+dc
        if is_val(maze, vis, nr, nc):
            par[nr][nc]=(r,c)
            if dfs(maze, vis, nr, nc, gr, gc):
                return True
    par[r][c]=None
    vis[r][c]=False
    return False

def dls(maze, vis, r, c, gr, gc, lim):
    if r==gr and c==gc:
        return True
    if lim<=0:
        return False
    vis[r][c]=True
    for dr, dc in mves:
        nr, nc=r+dr, c+dc
        if is_val(maze, vis, nr, nc):
            par[nr][nc]=(r,c)
            if dls(maze, vis, nr, nc, gr, gc, lim-1):
                return True
    par[r][c]=None
    vis[r][c]=False
    return False

def iddfs(maze, vis, sr, sc, gr, gc, mxdep):
    for dep in range(0,mxdep+1):
        for r in range(len(vis)):
            for c in range(len(vis[0])):
                vis[r][c]=False
                par[r][c]=None
        if dls(maze, vis, sr, sc, gr, gc, dep):
            return True
    return False

def bidec_bfs(maze, start, goal):
    if start == goal:
        return True, [start]
    qst=[start]
    qgl=[goal]
    vst=[[False for _ in range(len(maze[0]))] for _ in range(len(maze))]
    vgl=[[False for _ in range(len(maze[0]))] for _ in range(len(maze))]
    vst[start[0]][start[1]]=True
    vgl[goal[0]][goal[1]]=True
    pst={start:None}
    pgl={goal:None}

    insct=None

    while qst and qgl:
        if len(qst)<=len(qgl):
            cst=qst.pop(0)
            for dr, dc in mves:
                nr, nc=cst[0]+dr, cst[1]+dc
                if is_val(maze, vst, nr, nc):
                    pst[(nr, nc)]=cst
                    vst[nr][nc]=True
                    qst.append((nr, nc))
                    if vgl[nr][nc]:
                        insct=(nr, nc)
                        break
        else:
            cgl=qgl.pop(0)
            for dr, dc in mves:
                nr, nc=cgl[0]+dr, cgl[1]+dc
                if is_val(maze, vgl,nr, nc):
                    pgl[(nr, nc)]=cgl
                    vgl[nr][nc]=True
                    qgl.append((nr, nc))
                    if vst[nr][nc]:
                        insct=(nr, nc)
                        break
        if insct is not None:
            break
    if insct is None:
        return False, []

    path_s=[]
    cur=insct
    while cur is not None:
        path_s.append(cur)
        cur=pst[cur]
    path_s.reverse()
    path_g=[]
    cur=pgl[insct]
    while cur is not None:
        path_g.append(cur)
        cur=pgl[cur]
    return True, path_s+path_g

def recon_path(par, goal):
    path=[]
    cur=goal
    while cur is not None:
        path.append(cur)
        cur=par[cur[0]][cur[1]]
    pmaze=[row.copy() for row in maze]
    for r, c in path:
        pmaze[r][c]=2
    for row in pmaze:
        print(row)

start_node=(0,0)
goal_node=(8,8)

print("IDDFS: ")
if iddfs(maze, vis, start_node[0], start_node[1], goal_node[0], goal_node[1], 20):
    print("Path found")
    recon_path(par, goal_node)
else:
    print("No path found")

print("\nBidirectional BFS: ")
result, path=bidec_bfs(maze, start_node, goal_node)
if result:
    print("Path found:")
    for r,c in path:
        maze[r][c]=2
    for row in maze:
        print(row)
else:
    print("No path found")