class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
        if (row == triangle.size()) {
            return 0;
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        if (triangle[row].size() == 1) {
            return dp[row][col] = solve(triangle, row+1, col, dp) + triangle[row][col];
        }
        else {
            return dp[row][col] = min(solve(triangle, row+1, col, dp) + triangle[row][col], solve(triangle, row+1, col+1, dp) + triangle[row][col+1]);
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, -1));
        return solve(triangle, 0, 0, dp);
    }
};