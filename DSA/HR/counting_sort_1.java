import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Result {
    public static List<Integer> countingSort(List<Integer> arr) {
        List<Integer> list = new ArrayList<>(Collections.nCopies(100, 0));

        for (int num : arr) {
            list.set(num, list.get(num) + 1);
        }

        return list;
    }

}