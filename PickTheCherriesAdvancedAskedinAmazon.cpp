class Solution {
public:
    int path(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp)
    {
        if(j1 < 0 || j1 > n-1 || j2 < 0 || j2 > n-1)
            return -1e8;
        if(i == m-1)
        {
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        // exploring all path of robot1 robot2 simultaneously
        int maxpath = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++)
        {
            for(int dj2 = -1; dj2 <= 1; dj2++)
            {
                int currpath = 0;
                if(j1 == j2)
                    currpath = grid[i][j1];
                else
                    currpath = grid[i][j1] + grid[i][j2];
                currpath += path(i+1, j1+dj1, j2+dj2, grid, m, n, dp);
                maxpath = max(maxpath, currpath);
            }
        }
        return dp[i][j1][j2] = maxpath;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return path(0,0,n-1, grid, m, n, dp);
    }
};
