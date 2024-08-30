import java.util.HashSet;

class Result {
    public static String pangrams(String s) {
        HashSet<Character> uniqueChars = new HashSet<>();

        for (char c : s.toCharArray()) {
            if (c != ' ') {
                uniqueChars.add(Character.toLowerCase(c));
            }
        }

        return uniqueChars.size() == 26 ? "pangram" : "not pangram";
    }

}