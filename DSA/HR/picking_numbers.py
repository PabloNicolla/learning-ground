from typing import List


def pickingNumbers(a: List[int]) -> int:
    count = dict()
    for num in a:
        if num in count:
            count[num] += 1
        else:
            count[num] = 1

    ans = 0
    for k, v in count.items():
        curr = v
        if (k + 1) in count:
            curr += count[k + 1]
        ans = max(curr, ans)

    return ans
