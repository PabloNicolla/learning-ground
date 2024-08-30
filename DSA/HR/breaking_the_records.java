import java.util.Arrays;
import java.util.List;

class Result {
    public static List<Integer> breakingRecords(List<Integer> scores) {
        int currMin = scores.get(0), currMax = scores.get(0);
        int minCount = 0, maxCount = 0;

        for (int i = 1; i < scores.size(); i++) {
            int score = scores.get(i);
            if (score > currMax) {
                currMax = score;
                maxCount++;
            }
            if (score < currMin) {
                currMin = score;
                minCount++;
            }
        }

        return Arrays.asList(maxCount, minCount);
    }
}