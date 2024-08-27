import java.util.*;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] output = new int[temperatures.length];
        LinkedList<Map.Entry<Integer, Integer>> stack = new LinkedList<>();

        for (int i = 0; i < temperatures.length; ++i) {
            int temperature = temperatures[i];
            while (!stack.isEmpty() && stack.getLast().getValue() < temperature) {
                Map.Entry<Integer, Integer> removed = stack.removeLast();
                output[removed.getKey()] = i - removed.getKey();
            }
            stack.addLast(new AbstractMap.SimpleEntry<>(i, temperature));
        }

        return output;
    }
}