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
