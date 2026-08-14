class Solution {
public:

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        // Water or already visited
        if (grid[r][c] == '0')
            return;

        // Mark current land as visited
        grid[r][c] = '0';

        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1') {

                    count++;

                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};