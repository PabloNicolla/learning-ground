from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        nodes = {node: [] for node in range(n)}
        visited_nodes = set()
        used_edges = set()

        for edge_n1, edge_n2 in edges:
            nodes[edge_n1].append(edge_n2)
            nodes[edge_n2].append(edge_n1)

        stack = [0]

        while stack:
            node = stack.pop()
            if node in visited_nodes:
                return False
            visited_nodes.add(node)

            for node_to in nodes[node]:
                if (node, node_to) not in used_edges:
                    stack.append(node_to)
                    used_edges.add((node_to, node))

        return True if len(visited_nodes) == len(nodes) else False


class Solution2:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not n:
            return True
        adj = {i: [] for i in range(n)}
        for n1, n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)

        visit = set()

        def dfs(i: int, prev: int) -> bool:
            if i in visit:
                return False

            visit.add(i)
            for j in adj[i]:
                if j == prev:
                    continue
                if not dfs(j, i):
                    return False
            return True

        return dfs(0, -1) and n == len(visit)
