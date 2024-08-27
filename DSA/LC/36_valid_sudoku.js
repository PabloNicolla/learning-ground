function isValidSudoku(board) {
  let rows = Array.from({ length: 9 }, () => new Set());
  let cols = Array.from({ length: 9 }, () => new Set());
  let subgrids = Array.from({ length: 9 }, () => new Set());
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      const cell = board[i][j];
      if (cell === ".") continue;
      const subgridIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);
      if (rows[i].has(cell) || cols[j].has(cell) || subgrids[subgridIndex].has(cell)) {
        return false;
      }
      rows[i].add(cell);
      cols[j].add(cell);
      subgrids[subgridIndex].add(cell);
    }
  }
  return true;
}
export {};
