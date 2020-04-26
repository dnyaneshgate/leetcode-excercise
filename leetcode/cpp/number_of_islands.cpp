/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */

/*
 * class Solution {
 * private:
 *
 *     void explore(vector<vector<char>>& G, int r, int c, int M, int N) {
 *         G[r][c] = '2';
 *
 *         if(((r - 1) >= 0) && (G[r - 1][c] == '1')) explore(G, r - 1, c, M, N);
 *
 *         if(((c + 1) < N) && (G[r][c + 1] == '1')) explore(G, r, c + 1, M, N);
 *
 *         if(((r + 1) < M) && (G[r + 1][c] == '1')) explore(G, r + 1, c, M, N);
 *
 *         if(((c - 1) >= 0) && (G[r][c - 1] == '1')) explore(G, r, c - 1, M, N);
 *     }
 *
 *
 * public:
 *     int numIslands(vector<vector<char>>& grid) {
 *         int CC = 0;
 *         int M = grid.size();
 *         for(int r = 0; r < M; ++r) {
 *             int N = grid[r].size();
 *             for(int c = 0; c < N; ++c) {
 *                 if(grid[r][c] == '1') {
 *                     CC++;
 *                     explore(grid, r, c, M, N);
 *                 }
 *             }
 *         }
 *         return CC;
 *     }
 * };
 *
 * auto speedup = [](){
 *     ios_base::sync_with_stdio(false);
 *     cout.tie(NULL);
 *     return nullptr;
 * }();
 */

#include <bits/stdc++.h>

using namespace std;

int rows, cols;

bool is_safe(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &visited) {
    return (x >= 0) && (x < rows) && (y >= 0) && (y < cols) && grid[x][y] == '1' && !visited[x][y];
}

void dfs(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &visited) {
    static int row_nbr[] = {-1, 0, 0, 1};
    static int col_nbr[] = {0, -1, 1, 0};

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        if (is_safe(grid, x + row_nbr[i], y + col_nbr[i], visited)) {
            dfs(grid, x + row_nbr[i], y + col_nbr[i], visited);
        }
    }
}

int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0) {
        return 0;
    }

    rows = grid.size();
    cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                ++count;
                dfs(grid, i, j, visited);
            }
        }
    }
    // cout << count << endl;
    return count;
}

int main() {
    struct test_t {
        vector<vector<char>> grid;
        int expected;
    };

    vector<test_t> tests = {
        {
            {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'},
            },
            1,
        },
        {
            {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'},
            },
            3,
        },
        {
            {
                {'1', '1', '0', '1', '0', '1'},
                {'0', '1', '1', '1', '0', '1'},
                {'0', '0', '0', '0', '0', '1'},
                {'0', '0', '0', '1', '1', '0'},
            },
            3,
        },
        {
            {
                {'1', '1', '1', '1', '1', '1', '1'},
                {'0', '0', '0', '0', '0', '0', '1'},
                {'1', '1', '1', '1', '1', '0', '1'},
                {'1', '0', '0', '0', '1', '0', '1'},
                {'1', '0', '1', '0', '1', '0', '1'},
                {'1', '0', '1', '1', '1', '0', '1'},
                {'1', '1', '1', '1', '1', '1', '1'},
            },
            1,
        },
    };

    for (auto &t : tests) {
        assert(numIslands(t.grid) == t.expected);
    }

    return 0;
}
