from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = defaultdict(list)

        for str in strs:
            count = [0] * 26

            for c in str:
                count[ord(c) - ord('a')] += 1
            result[tuple(count)].append(str)

        return result.values()
