class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> seen = {{0,-1}};
        
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i] % k) % k;
            seen.insert({prefix, i});
            if (i - seen[prefix] > 1)
                return true;
        }
        
        return false;
    }
};