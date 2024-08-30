import java.util.List;

class Result {

    public static int divisibleSumPairs(int n, int k, List<Integer> ar) {
        int[] freq = new int[k];
        int count = 0;

        for (int i = 0; i < n; i++) {
            int mod = ar.get(i) % k;
            count += freq[(k - mod) % k];
            freq[mod]++;
        }

        return count;
    }

}