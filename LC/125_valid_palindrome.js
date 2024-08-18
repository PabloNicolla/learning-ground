"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function isPalindrome(s) {
  var index = 0;
  var size = s.length;
  var leftBuffer = 0;
  var rightBuffer = 0;
  var predicate = function (c) {
    return (c.toLowerCase() >= "a" && c.toLowerCase() <= "z") || (c >= "0" && c <= "9");
  };
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
