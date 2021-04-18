class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> seen;
        seen[0]++; // will help to calculate ans if the sum till current element is equals to k
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // doing prefix sum
            ans += seen[sum-k]; // here we are checking if previously we encountered (sum-k)
            // if so, then it means sum - (sum - k) == k, so we can add that to  our ans
            seen[sum]++; // here we are simply storing the current sum in a hashmap
        }
        
        return ans;
    }
};