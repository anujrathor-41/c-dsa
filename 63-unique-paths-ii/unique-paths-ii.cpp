

class Solution {
public:
    int t[101][101];

    int solve(vector<vector<int>>& grid, int m, int n) {

        // Grid khatam ho gayi
        if(m == 0 || n == 0)
            return 0;

        // Agar current cell obstacle hai
        if(grid[m-1][n-1] == 1)
            return 0;

        // Starting cell tak pahunch gaye
        if(m == 1 && n == 1)
            return 1;

        if(t[m][n] != -1)
            return t[m][n];

        return t[m][n] =
            solve(grid, m-1, n) +
            solve(grid, m, n-1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return solve(obstacleGrid, m, n);
    }
};