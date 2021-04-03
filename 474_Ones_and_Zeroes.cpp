class Solution {
public:
    int solve(vector<int>& arr0, vector<int>& arr1, int m, int n, int s, vector<vector<vector<int>>>& dp) {
        if (s <= 0)
            return 0;
        if (m < 0 || n < 0)
            return 0;
        if (dp[s][m][n] != -1)
            return dp[s][m][n];
        
        if (arr0[s-1] <= m && arr1[s-1] <= n) {
            return dp[s][m][n] = max(solve(arr0, arr1, m-arr0[s-1], n-arr1[s-1], s-1, dp) + 1, solve(arr0, arr1, m, n, s-1, dp));
        }
        else {
            return dp[s][m][n] = solve(arr0, arr1, m, n, s-1, dp);
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<int> arr0;
        vector<int> arr1;
        
        for (string str : strs) {
            int cnt0 = 0;
            int cnt1 = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '0') cnt0++;
                else cnt1++;
            }
            arr0.push_back(cnt0);
            arr1.push_back(cnt1);
        }
        
        vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        //vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        int ans = solve(arr0, arr1, m, n, s, dp);
        
        return ans;
    }
};