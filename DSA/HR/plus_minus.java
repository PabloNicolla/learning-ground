import java.util.List;

class Result {
    public static void plusMinus(List<Integer> arr) {
        int neg = 0, pos = 0, zero = 0;
        for (int num : arr) {
            if (num == 0) {
                zero++;
            } else if (num < 0) {
                neg++;
            } else {
                pos++;
            }
        }
        int total = neg + pos + zero;
        System.out.printf("%.6f\n", (float) pos / total);
        System.out.printf("%.6f\n", (float) neg / total);
        System.out.printf("%.6f\n", (float) zero / total);
    }
}