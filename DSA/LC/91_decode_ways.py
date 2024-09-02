class Solution:
    def numDecodings(self, s: str) -> int:
        memory = {len(s): 1}

        def rec(index):
            if index in memory:
                return memory[index]
            if s[index] == '0':
                return 0

            count = rec(index + 1)

            if (
                index + 1 < len(s)
                and (
                    s[index] == '1'
                    or (s[index] == '2' and s[index + 1] in "0123456")
                )
            ):
                count += rec(index + 2)

            memory[index] = count
            return count

        return rec(0)
