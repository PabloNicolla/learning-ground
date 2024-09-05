from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        nodes = {node: [] for node in range(n)}
        visited = [False] * n
        count = 0

        for node1, node2 in edges:
            nodes[node1].append(node2)
            nodes[node2].append(node1)

        for i in range(n):
            if visited[i]:
                continue
            stack = [i]

            while stack:
                node = stack.pop()
                visited[node] = True

                for node_to in nodes[node]:
                    if not visited[node_to]:
                        stack.append(node_to)
            count += 1
        return count


class UnionFind:
    def __init__(self):
        self.f = {}

    def findParent(self, x: int) -> int:
        y = self.f.get(x, x)
        if x != y:
            y = self.f[x] = self.findParent(y)
        return y

    def union(self, x: int, y: int):

        self.f[self.findParent(x)] = self.findParent(y)


class Solution2:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = UnionFind()
        for a, b in edges:
            dsu.union(a, b)
        return len(set(dsu.findParent(x) for x in range(n)))
