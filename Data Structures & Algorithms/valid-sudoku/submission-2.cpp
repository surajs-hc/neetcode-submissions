class Solution {
private:
    bool verify_arr[9];
    void start_verifying() {
        for (int i = 0; i < 9; ++i) {
            verify_arr[i] = false;
        }
    }
    bool verify(char c) {
        if (c == '.') {
            return true;
        }
        if (verify_arr[c - '1']) {
            return false;
        }
        verify_arr[c - '1'] = true;
        return true;
    }

public:
    bool checkBox(int boxNum, const vector<vector<char>>& board) {
        int x = (boxNum % 3) * 3;
        int y = (boxNum / 3) * 3;

        start_verifying();
        for (int row = y; row < y + 3; ++row) {
            for (int col = x; col < x + 3; ++col) {
                if (!verify(board[row][col])) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int row = 0; row < 9; ++row) {
            start_verifying();
            for (int col = 0; col < 9; ++col) {
                if (!verify(board[row][col])) {
                    return false;
                }
            }
        }

        // cols
        for (int col = 0; col < 9; ++col) {
            start_verifying();
            for (int row = 0; row < 9; ++row) {
                if (!verify(board[row][col])) {
                    return false;
                }
            }
        }

        // boxes
        for (int i = 0; i < 9; ++i) {
            if (!checkBox(i, board)) {
                return false;
            }
        }

        return true;
    }
};
