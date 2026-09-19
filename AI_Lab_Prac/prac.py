graph={}
vis=set()
par={}
path=[]

input_edges=input("Enter edges (eg. 1 2, 3 4, ...): ").split(",")

for edge in input_edges:
    edge=edge.strip()
    if not edge:
        continue
    u,v = map(int, edge.split())
    if u not in graph:
        graph[u]=[]
    if v not in graph:
        graph[v]=[]
    graph[u].append(v)
    graph[v].append(u)


def dfs(graph, start, goal):
    if start not in graph or goal not in graph:
        return False
    if start==goal:
        return True
    vis.add(start)
    for child in graph[start]:
        if child not in vis:
            par[child]=start
            if dfs(graph, child, goal):
                return True
    return False

def dls(graph, start, goal, lim):
    if start not in graph or goal not in graph:
        return False
    if start==goal:
        return True
    if lim<=0:
        return False
    vis.add(start)
    for child in graph[start]:
        if child not in vis:
            par[child]=start
            if dls(graph, child, goal, lim-1):
                return True
    vis.remove(start)
    return False

def iddfs(graph, start, goal, mxdep):
    for dep in range(0, mxdep+1):
        vis.clear()
        par.clear()
        if dls(graph, start, goal, dep):
            return True
    return False

def bidir_bfs(graph, start, goal):
    if start not in graph or goal not in graph:
        return False, []
    if start==goal:
        return True, [start]
    qst=[start]
    qgl=[goal]
    vst={start}
    vgl={goal}
    pst={start: None}
    pgl={goal: None}
    insct=None

    while qst and qgl:
        if len(qst)<=len(qgl):
            cst=qst.pop(0)
            for child in graph[cst]:
                if child not in vst:
                    vst.add(child)
                    pst[child]=cst
                    qst.append(child)
                    if child in vgl:
                        insct=child
                        break
        else:
            cgl=qgl.pop(0)
            for child in graph[cgl]:
                if child not in vgl:
                    vgl.add(child)
                    pgl[child]=cgl
                    qgl.append(child)
                    if child in vst:
                        insct=child
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

start_node=int(input("Enter start node: "))
goal_node=int(input("Enter goal node: "))

result, path=bidir_bfs(graph, start_node, goal_node)

if result:
    print("Path found:", path)
else:
    print("No path found.")
