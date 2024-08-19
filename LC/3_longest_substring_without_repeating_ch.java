class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> seenSlidingView = new HashMap<>();
        int startIndex = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (seenSlidingView.containsKey(c)) {
                if (maxLength < (i - startIndex)) {
                    maxLength = i - startIndex;
                }
                int possibleNewStart = seenSlidingView.get(c) + 1;
                if (possibleNewStart > startIndex) {
                    startIndex = possibleNewStart;
                }
            }
            seenSlidingView.put(c, i);
        }
        if (maxLength < (s.length() - startIndex)) {
            maxLength = s.length() - startIndex;
        }
        return maxLength;
    }
}
