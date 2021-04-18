class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> seen = {{0,1}};
        
        for (int i = 0; i < A.size(); i++) {
            sum += ((A[i] % K) + K) % K;
            ans += seen[sum % K];
            seen[sum % K]++;
        }
        
        return ans;
    }
};