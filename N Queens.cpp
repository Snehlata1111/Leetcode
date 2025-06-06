class Solution {
private:
    bool isQueenSafe(int row, int col, int n, vector<vector<bool>>& board) {
        // for d1 => r--, c-- 
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == true) {
                return false;
            }
        }

        // for d2 => r--, c constant
        for (int r = row - 1; r >= 0; r--) {
            if (board[r][col] == true) {
                return false;
            }
        }

        // for d3 => r--, c++
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == true) {
                return false;
            }
        }

        return true;
    }

    void prepareBoard(vector<vector<bool>>& board, vector<vector<string>>& ans, int n) {
        vector<string> subAns;
        for (int row = 0; row < n; row++) {
            string sb;
            for (int col = 0; col < n; col++) {
                if (board[row][col] == true) {
                    sb.push_back('Q');
                } else {
                    sb.push_back('.');
                }
            }
            subAns.push_back(sb);
        }
        ans.push_back(subAns);
    }

    void helper(int row, vector<vector<bool>>& board, int n, vector<vector<string>>& ans) {
        if (row == n) {
            prepareBoard(board, ans, n);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isQueenSafe(row, col, n, board) == true) {
                board[row][col] = true;
                helper(row + 1, board, n, ans);
                board[row][col] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        helper(0, board, n, ans);
        return ans;
    }
};
