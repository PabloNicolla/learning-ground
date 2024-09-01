import java.util.List;

class Result {
    public static int birthday(List<Integer> s, int d, int m) {
        int fastPtr = 0, slowPtr = 0;
        int currSum = 0, differentWaysCount = 0;

        for (; fastPtr < m && fastPtr < s.size(); fastPtr++) {
            currSum += s.get(fastPtr);
        }

        if (currSum == d) {
            differentWaysCount += 1;
        }

        for (; fastPtr < s.size(); fastPtr++) {
            currSum -= s.get(slowPtr);
            slowPtr++;
            currSum += s.get(fastPtr);
            if (currSum == d) {
                differentWaysCount += 1;
            }
        }

        return differentWaysCount;
    }

}