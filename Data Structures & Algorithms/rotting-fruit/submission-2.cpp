class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int height = grid.size();
        int width = grid[0].size();

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
            }
        }

        // bfs
        int minutes = -1;
        while (!q.empty()) {
            ++minutes;
            int rottedFruits = q.size();
            
            for (int fruit = 0; fruit < rottedFruits; ++fruit) {
                const auto [row, col] = q.front();
                q.pop();

                int dRow[] = {0, 0, -1, 1};
                int dCol[] = {-1, 1, 0, 0};
                for (int d = 0; d < 4; ++d) {
                    int nRow = row + dRow[d];
                    int nCol = col + dCol[d];

                    if (nRow >= 0 && nRow < height && nCol >= 0 && nCol < width && grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }

        return max(minutes, 0);
    }
};
