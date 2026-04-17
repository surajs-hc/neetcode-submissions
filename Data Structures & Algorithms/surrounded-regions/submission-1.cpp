class Solution {
vector<int> dR = {0, 0, -1, 1};
vector<int> dC = {-1, 1, 0, 0};
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int height = board.size();
        int width = board[0].size();
        char MID = 'I';

        for (int r = 0; r < height; ++r) {
            if (board[r][0] == 'O') {
                q.push({r, 0});
                board[r][0] = MID;
            }
            if (board[r][width - 1] == 'O') {
                q.push({r, width - 1});
                board[r][width - 1] = MID;
            }
        }
        for (int c = 0; c < width; ++c) {
            if (board[0][c] == 'O') {
                q.push({0, c});
                board[0][c] = MID;
            }
            if (board[height - 1][c] == 'O') {
                q.push({height - 1, c});
                board[height - 1][c] = MID;
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int newR = row + dR[d];
                int newC = col + dC[d];

                if (newR >= 0 && newC >= 0 && newR < height && newC < width && board[newR][newC] == 'O') {
                    board[newR][newC] = MID;
                    q.push({newR, newC});
                }
            }
        }

        for (vector<char>& row : board) {
            for (char& box : row) {
                if (box == 'O') {
                    box = 'X';
                }
                if (box == MID) {
                    box = 'O';
                }
            }
        }
    }
};
