class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // calculate prefix sum for each row
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
        
        // using two loops with i and j for looping through each column
        // inside that used one more loop for looping through each row between that columns and calculate target sum
        int sum;
        for (int i = 0; i < n; i++) {
            for (int j = i ; j < n; j++) {
                unordered_map<int,int> seen = {{0,1}};
                sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                    ans += seen[sum - target];
                    seen[sum]++;
                }
            }
        }
        
        return ans;
    }
};