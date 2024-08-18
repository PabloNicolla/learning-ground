import java.util.HashMap;

class Solution {
  public static boolean isAnagram(String s, String t) {
    // char[] s_arr = s.toCharArray();
    // char[] t_arr = t.toCharArray();
    // Arrays.sort(s_arr);
    // Arrays.sort(t_arr);
    // s = new String(s_arr);
    // t = new String(t_arr);
    // return s.equals()
    HashMap<Character, Integer> s_map = new HashMap<>();
    HashMap<Character, Integer> t_map = new HashMap<>();

    if (s.length() != t.length()) {
      return false;
    }

    for (char c : s.toCharArray()) {
      s_map.put(c, s_map.getOrDefault(c, 0) + 1);
    }

    for (char c : t.toCharArray()) {
      t_map.put(c, t_map.getOrDefault(c, 0) + 1);
    }

    if (t_map.size() != s_map.size()) {
      return false;
    }

    for (Character c : s_map.keySet()) {
      if (!t_map.containsKey(c) || !t_map.get(c).equals(s_map.get(c))) {
        return false;
      }
    }
    return true;
  }
}
