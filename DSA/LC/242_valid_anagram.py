class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # return sorted(s) == sorted(t) # optional solution
        s_map, t_map = {}, {}

        if len(s) != len(t):
            return False

        for c in s:
            s_map[c] = 1 + s_map.get(c, 0)

        for c in t:
            t_map[c] = 1 + t_map.get(c, 0)

        if len(s_map) != len(t_map):
            return False

        for k, v in s_map.items():
            if t_map.get(k, -1) != v:
                return False
        return True
