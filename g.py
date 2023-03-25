from collections import defaultdict
from queue import Queue


def solve():
    N = int(input())
    Vals = list(map(int, input().split()))
    Edges = [tuple(map(int, input().split())) for _ in range(N-1)]

    graph = defaultdict(list)
    for u, v in Edges:
        graph[u].append(v)
        graph[v].append(u)

    levels = {}
    stack = [(1, 0)]
    print("Graph\n")
    # while stack:
    #     node, level = stack.pop()
    #     if level not in levels:
    #         levels[level] = []
    #     levels[level].append(node)
    #     for neighbor in graph[node]:
    #         if neighbor != 1:
    #             print(neighbor)
    #             stack.append((neighbor, level+1))
    q = [(1, 0)]
    vis = [0]*(N+1)
    vis[1] = 1
    while q:
        node, level = q[-1]
        q.pop()
        if level not in levels:
            levels[level] = []
        levels[level].append(node)
        for neighbor in graph[node]:
            if vis[neighbor] != 1:
                q.append((neighbor, level+1))
                print(neighbor, level+1)
                vis[neighbor] = 1
    print("1")
    max_scores = []
    print(levels)
    print(Vals)
    for level, nodes in levels.items():
        print(nodes)
        xor_sum = 0
        for node in nodes:
            xor_sum ^= Vals[node]
        if len(nodes) < 2:
            max_scores.append(xor_sum)
            continue
        max_score = xor_sum
        for node1 in nodes:
            for node2 in nodes:
                if node1 == node2:
                    continue
                new_score = xor_sum ^ Vals[node1] ^ Vals[node2]
                max_score = max(max_score, new_score)
        max_scores.append(max_score)
    return max_scores


if __name__ == "__main__":
    print(*solve())
