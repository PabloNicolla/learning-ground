import collections


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_map, s1_len, matches_in_view = collections.Counter(s1), len(s1), 0

        for i in range(len(s2)):
            head_char = s2[i]
            tail_char = None

            if i >= s1_len:
                tail_char = s2[i - s1_len]

            if head_char in s1_map:
                if s1_map[head_char] == 0:
                    matches_in_view -= 1
                s1_map[head_char] -= 1
                if s1_map[head_char] == 0:
                    matches_in_view += 1

            if tail_char in s1_map:
                if s1_map[tail_char] == 0:
                    matches_in_view -= 1
                s1_map[tail_char] += 1
                if s1_map[tail_char] == 0:
                    matches_in_view += 1

            if matches_in_view == len(s1_map):
                return True

        return False
