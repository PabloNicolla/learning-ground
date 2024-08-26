from typing import List


class Solution:

    def encode(self, strs: List[str]) -> str:
        delimiter = '\u001F'
        if len(strs) == 0:
            return "\u001F"
        return delimiter.join(strs)

    def decode(self, s: str) -> List[str]:
        delimiter = '\u001F'
        if s == delimiter:
            return []
        return s.split(delimiter)
