function checkInclusion(s1: string, s2: string): boolean {
  const s1_count = new Map<string, number>();
  const s2_sliding_view = new Map<string, number>();

  if (s1.length > s2.length) return false;

  for (let c of s1) {
    s1_count.set(c, (s1_count.get(c) || 0) + 1);
  }

  for (let i = 0; i < s1.length; ++i) {
    const c = s2.charAt(i);
    s2_sliding_view.set(c, (s2_sliding_view.get(c) || 0) + 1);
  }

  const checkIfValidPermutation = () => {
    const entries = s1_count.entries();
    for (let [key, value] of entries) {
      if (s2_sliding_view.get(key) != value) {
        return false;
      }
    }
    return true;
  };

  const removeFromSlidingView = (c: string) => {
    const value = s2_sliding_view.get(c)!;
    if (value == 1) s2_sliding_view.delete(c);
    else s2_sliding_view.set(c, value - 1);
  };

  if (checkIfValidPermutation()) return true;

  for (let i = s1.length; i < s2.length; ++i) {
    removeFromSlidingView(s2.charAt(i - s1.length));
    s2_sliding_view.set(s2.charAt(i), (s2_sliding_view.get(s2.charAt(i)) || 0) + 1);
    if (checkIfValidPermutation()) return true;
  }

  return false;
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts
// tsc LC/567_permutation_in_string.ts --lib "es2017" --target 'es2015'
// tsc --downlevelIteration ...

// tsc --project tsconfig.json

export {};
