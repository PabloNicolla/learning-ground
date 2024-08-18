function isPalindrome(s: string): boolean {
  let index = 0;
  let size = s.length;
  let leftBuffer = 0;
  let rightBuffer = 0;

  const predicate = (c: string) => (c.toLowerCase() >= "a" && c.toLowerCase() <= "z") || (c >= "0" && c <= "9");

  s = s.toLowerCase();

  for (index; index < Math.floor(size / 2); ++index) {
    while (index + leftBuffer < size && !predicate(s[index + leftBuffer])) {
      leftBuffer++;
    }
    while (size - 1 - index - rightBuffer >= 0 && !predicate(s[size - 1 - index - rightBuffer])) {
      rightBuffer++;
    }
    if (s[index + leftBuffer] != s[size - 1 - index - rightBuffer]) {
      return false;
    }
  }
  return true;
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

export {};
