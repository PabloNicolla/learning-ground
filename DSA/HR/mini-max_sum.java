import java.util.List;

class Result {
    public static void miniMaxSum(List<Integer> arr) {
        long min = arr.get(0), max = arr.get(0), total = 0;
        for (int num : arr) {
            if (num < min) {
                min = num;
            }
            if (num > max) {
                max = num;
            }
            total += num;
        }
        System.out.printf("%d %d\n", total - max, total - min);
    }

}