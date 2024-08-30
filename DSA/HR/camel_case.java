import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String[] parts = scanner.nextLine().split(";");
            String operation = parts[0];
            String type = parts[1];
            String words = parts[2];

            if (operation.equals("S")) {
                System.out.println(splitCamelCase(words));
            } else if (operation.equals("C")) {
                System.out.println(combineWords(words, type));
            }
        }
        scanner.close();
    }

    static String splitCamelCase(String s) {
        return s.replaceAll("([a-z])([A-Z]+)", "$1 $2").toLowerCase().replace("()", "");
    }

    static String combineWords(String s, String type) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            if (i == 0 && (type.equals("V") || type.equals("M"))) {
                sb.append(words[i].toLowerCase());
            } else {
                sb.append(Character.toUpperCase(words[i].charAt(0)) + words[i].substring(1).toLowerCase());
            }
        }

        if (type.equals("M")) {
            sb.append("()");
        }

        return sb.toString();
    }
}
