#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> col;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;

        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, col, posDiag, negDiag, board, res);
        return res;
    }

private:
    void backtrack(int r, int n, unordered_set<int> &col, unordered_set<int> &posDiag,
                   unordered_set<int> &negDiag, vector<string> &board,
                   vector<vector<string>> &res)
    {
        if (r == n)
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
            {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, col, posDiag, negDiag, board, res);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};
