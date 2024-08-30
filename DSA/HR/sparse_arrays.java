import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Result {
    public static List<Integer> matchingStrings(List<String> strings, List<String> queries) {
        HashMap<String, Integer> freq = new HashMap<>();

        for (String str : strings) {
            if (freq.containsKey(str)) {
                freq.put(str, freq.get(str) + 1);
            } else {
                freq.put(str, 1);
            }
        }

        List<Integer> output = new ArrayList<>();
        for (String q : queries) {
            output.add(freq.getOrDefault(q, 0));
        }
        return output;
    }

}