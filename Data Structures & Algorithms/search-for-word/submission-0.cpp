class Solution {
private:
    bool dfs(vector<vector<char>>& board, int r, int c, int index, const string& word) {
        int wSize = word.size();
        if (index == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[r].size()) {
            return false;
        }
        if (board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';
        bool result = dfs(board, r - 1, c, index + 1, word) ||
            dfs(board, r + 1, c, index + 1, word) ||
            dfs(board, r, c - 1, index + 1, word) ||
            dfs(board, r, c + 1, index + 1, word);
        board[r][c] = temp;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0, height = board.size(); row < height; ++row) {
            for (int col = 0, width = board[row].size(); col < width; ++col) {
                if (dfs(board, row, col, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
