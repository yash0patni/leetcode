class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        
        for (int num : nums2) {
            if (s.erase(num))
                res.push_back(num);
        }
        
        return res;
        
        /*
        // Naive solution | Time - O(m*n) | Space - O(n)
        set<int> s;
        vector<int> res;
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j])
                    s.insert(nums1[i]);
            }
        }
        
        for (auto x = s.begin(); x != s.end(); ++x) {
            res.push_back(*x);
        }
        return res;*/
    }
};