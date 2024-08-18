"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function isValidSudoku(board) {
  var rows = Array.from({ length: 9 }, function () {
    return new Set();
  });
  var cols = Array.from({ length: 9 }, function () {
    return new Set();
  });
  var subgrids = Array.from({ length: 9 }, function () {
    return new Set();
  });
  for (var i = 0; i < 9; i++) {
    for (var j = 0; j < 9; j++) {
      var cell = board[i][j];
      if (cell === ".") continue;
      var subgridIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);
      if (
        rows[i].has(cell) ||
        cols[j].has(cell) ||
        subgrids[subgridIndex].has(cell)
      ) {
        return false;
      }
      rows[i].add(cell);
      cols[j].add(cell);
      subgrids[subgridIndex].add(cell);
    }
  }
  return true;
}
