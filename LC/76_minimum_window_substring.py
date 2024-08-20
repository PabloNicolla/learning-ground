from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_counter_map = defaultdict(int)
        t_index_map = defaultdict(list)
        remaining_counter = len(t)
        start = None

        current_len = 0
        min_len = None
        min_tuple = None

        for c in t:
            t_counter_map[c] += 1
            t_index_map[c] = list()

        for i, c in enumerate(s):
            current_len += 1
            if c in t_counter_map:
                if start is None:
                    current_len = 0
                    start = i

                if t_counter_map[c] >= 1:
                    t_index_map[c].append(i)
                    remaining_counter -= 1
                    t_counter_map[c] -= 1
                else:
                    old_start = t_index_map[c][0]
                    t_index_map[c].pop(0)
                    t_index_map[c].append(i)
                    if old_start == start:
                        new_min_index = i
                        for index_list in t_index_map.values():
                            if len(index_list) > 0 and index_list[0] < new_min_index:
                                new_min_index = index_list[0]
                        current_len += start - new_min_index
                        start = new_min_index

                if remaining_counter == 0 and (min_len is None or current_len < min_len):
                    min_len = current_len
                    min_tuple = (start, i)

        return s[min_tuple[0]: min_tuple[1] + 1] if min_len is not None else ""
