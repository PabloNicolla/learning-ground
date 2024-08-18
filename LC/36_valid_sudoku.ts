function isValidSudoku(board: string[][]): boolean {
  // Initialize sets for rows, columns, and subgrids
  let rows: Set<string>[] = Array.from({ length: 9 }, () => new Set());
  let cols: Set<string>[] = Array.from({ length: 9 }, () => new Set());
  let subgrids: Set<string>[] = Array.from({ length: 9 }, () => new Set());

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      const cell = board[i][j];

      // Skip empty cells
      if (cell === ".") continue;

      // Calculate the index for the 3x3 subgrid
      const subgridIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);

      // Check for duplicates in the row, column, or subgrid
      if (
        rows[i].has(cell) ||
        cols[j].has(cell) ||
        subgrids[subgridIndex].has(cell)
      ) {
        return false;
      }

      // Add the cell value to the appropriate sets
      rows[i].add(cell);
      cols[j].add(cell);
      subgrids[subgridIndex].add(cell);
    }
  }

  return true;
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

export {};
