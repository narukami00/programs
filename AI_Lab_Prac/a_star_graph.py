import heapq


def astar(graph, start, goal, h):
    q=[(h(start),0, start, [start])]
    dist={start:0}

    while q:
        f, cost, cur, path=heapq.heappop(q)

        if cur==goal:
            return path, cost

        if cost>dist[cur]:
            continue

        for v,w in graph.get(cur, []):
            new_cost=cost+w

            if new_cost<dist.get(v, float('inf')):
                dist[v]=new_cost
                heapq.heappush(q, (new_cost+h(v), new_cost, v, path+[v]))

    return None, float('inf')



graph={}
print("Enter edges as 'FROM TO WEIGHT' (empty line to finish):")
while True:
    line=input().strip()
    if not line: break
    u,v,w=line.split()
    graph.setdefault(u,[]).append((v,int(w)))
    graph.setdefault(v,[])

h_vals={}
print("Enter heuristic values as 'NODE VALUE' (empty line to finish):")
while True:
    line=input().strip()
    if not line: break
    k,v=line.split()
    h_vals[k]=int(v)
h=lambda x: h_vals[x]

print("Enter start and goal nodes:")
s=input("Start: ").strip()
t=input("Goal: ").strip()

path, cost = astar(graph, s, t, h)

if path:
    print("Path:", '->'.join(path))
    print("Cost:", cost)
else:
    print("No path found.")