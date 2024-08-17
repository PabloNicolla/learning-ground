class Solution {
  /**
   * @param {string} s
   * @param {string} t
   * @return {boolean}
   */
  isAnagram(s, t) {
    // return s.toLowerCase().split('').sort().join('') === t.toLowerCase().split('').sort().join('');
    const s_map = {};
    const t_map = {};

    if (s.length != t.length) {
      return false;
    }

    s.split("").forEach((c) => {
      s_map[c] = (s_map[c] || 0) + 1;
    });

    t.split("").forEach((c) => {
      t_map[c] = (t_map[c] || 0) + 1;
    });

    const s_keys = Object.keys(s_map);
    const t_keys = Object.keys(t_map);

    if (s_keys.length != t_keys.length) {
      return false;
    }

    let outcome = true;

    s_keys.forEach((k) => {
      if (t_map[k] !== s_map[k]) {
        outcome = false;
        return false;
      }
    });

    return outcome;
  }
}
