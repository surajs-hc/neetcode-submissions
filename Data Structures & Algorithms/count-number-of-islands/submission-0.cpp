class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        queue<pair<int, int>> q;
        int dR[] = {0, 0, -1, 1};
        int dC[] = {-1, 1, 0, 0};

        for (int i = 0, h = grid.size(); i < h; ++i) {
            for (int j = 0, w = grid[j].size(); j < w; ++j) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                    ++numIslands;
                    while (!q.empty()) {
                        const auto [r, c] = q.front();
                        q.pop();
                        
                        for (int d = 0; d < 4; ++d) {
                            int nR = r + dR[d];
                            int nC = c + dC[d];

                            if (nR >= 0 && nR < h && nC >= 0 && nC < w && grid[nR][nC] == '1') {
                                q.push({nR, nC});
                                grid[nR][nC] = '0';
                            }
                        }
                    }
                }
            }
        }

        return numIslands;
    }
};
