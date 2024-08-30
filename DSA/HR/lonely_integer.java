import java.util.*;

class Result {
    public static int lonelyinteger(List<Integer> a) {
        Collections.sort(a);
        int index = a.size() - 1;
        boolean notFound = true;
        for (int i = 1; i < a.size() && notFound; i += 2) {
            if (!a.get(i - 1).equals(a.get(i))) {
                index = i - 1;
                notFound = false;
            }
        }
        return a.get(index);
    }
}