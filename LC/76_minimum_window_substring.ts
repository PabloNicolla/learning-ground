function minWindow(s: string, t: string): string {
  let windowMap: Map<string, number> = new Map();
  let minWindow: number[] | null = null;
  let minLen = Infinity;

  for (let c of t) {
    windowMap.set(c, (windowMap.get(c) || 0) + 1);
  }

  let have = 0;
  let start = 0;
  let need = windowMap.size;

  for (let i = 0; i < s.length; ++i) {
    const currChar = s[i];
    const currValue = windowMap.get(currChar);
    if (currValue != undefined) {
      windowMap.set(currChar, currValue - 1);
      if (currValue - 1 == 0) {
        have++;
      }
    }

    while (need == have) {
      const startChar = s[start];
      const startValue = windowMap.get(startChar);
      if (startValue != undefined) {
        windowMap.set(startChar, startValue + 1);
        if (startValue + 1 > 0) {
          have--;
          if (i - start + 1 < minLen) {
            minLen = i - start + 1;
            minWindow = [start, i];
          }
        }
      }
      start++;
    }
  }
  return minWindow ? s.substring(minWindow[0], minWindow[1] + 1) : "";
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

export {};
