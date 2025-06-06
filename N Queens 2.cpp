class Solution {
private:
    bool isQueenSafe(int row, int col, int n, bool board[][20]) {
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

    int helper(int row, int n, bool board[][20]) {
        if (row == n) {
            return 1;
        }

        int count = 0;
        for (int col = 0; col < n; col++) {
            if (isQueenSafe(row, col, n, board) == true) {
                board[row][col] = true;
                count += helper(row + 1, n, board);
                board[row][col] = false;
            }
        }

        return count;
    }

public:
    int totalNQueens(int n) {
        bool board[20][20] = {false};  // fixed size to avoid dynamic allocation
        return helper(0, n, board);
    }
};
