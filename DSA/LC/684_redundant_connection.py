
from typing import List


class Solution1:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        nodes = {node: [] for node in range(1, len(edges) + 1)}

        for node1, node2 in edges:
            nodes[node1].append(node2)
            nodes[node2].append(node1)

        visited = set()
        path = []

        def dfs(node, prev):
            visited.add(node)
            path.append(node)
            for node_to in nodes[node]:
                if node_to != prev:
                    if node_to in visited:
                        path.append(node_to)
                        return True
                    if dfs(node_to, node):
                        return True
            visited.remove(node)
            path.pop()
            return False

        dfs(1, None)

        cycle_start = path[-1]
        cycle_nodes = set()
        for i in range(len(path) - 2, -1, -1):
            cycle_nodes.add((path[i], path[i + 1]))
            cycle_nodes.add((path[i + 1], path[i]))
            if path[i] == cycle_start:
                break

        for i in range(len(edges) - 1, -1, -1):
            if (edges[i][0], edges[i][1]) in cycle_nodes:
                return edges[i]


class Solution2:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        par = [i for i in range(len(edges) + 1)]
        rank = [1] * (len(edges) + 1)

        def find(n):
            p = par[n]
            while p != par[p]:
                par[p] = par[par[p]]
                p = par[p]
            return p

        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return False
            if rank[p1] > rank[p2]:
                par[p2] = p1
                rank[p1] += rank[p2]
            else:
                par[p1] = p2
                rank[p2] += rank[p1]
            return True

        for n1, n2 in edges:
            if not union(n1, n2):
                return [n1, n2]


class Solution3:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        nodes = {node: [] for node in range(1, len(edges) + 1)}

        for node1, node2 in edges:
            nodes[node1].append(node2)
            nodes[node2].append(node1)

        visited = set()
        path = []

        def dfs(node, prev):
            visited.add(node)
            for node_to in nodes[node]:
                if node_to != prev:
                    if node_to in visited or dfs(node_to, node):
                        path.insert(0, node_to)
                        return True
            visited.remove(node)
            return False

        dfs(1, None)

        cycle_start = path[-1]
        cycle_edges = set()
        for i in range(len(path) - 2, -1, -1):
            cycle_edges.add((path[i], path[i + 1]))
            if path[i] == cycle_start:
                break

        for i in range(len(edges) - 1, -1, -1):
            if (edges[i][0], edges[i][1]) in cycle_edges or (edges[i][1], edges[i][0]) in cycle_edges:
                return edges[i]
