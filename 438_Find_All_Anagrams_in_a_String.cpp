class Solution {
public:
    bool isValid(vector<int>& pA, vector<int>& sA) {
        for (int i = 0; i < 26; i++) {
            if (pA[i] != sA[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length())
            return res;
        vector<int> pA(26, 0);
        vector<int> sA(26, 0);
        
        for (int i = 0; i < p.length(); i++) {
            pA[p[i] - 'a']++;
        }
        int i;
        for (i = 0; i < p.length(); i++) {
            sA[s[i] - 'a']++;
        }
        if (isValid(pA, sA)) res.push_back(0);
        for ( ; i < s.length(); i++) {
            sA[s[i] - 'a']++;
            sA[s[i - p.length()] - 'a']--;
            if (isValid(pA, sA))
                res.push_back(i - p.length() + 1);
        }
        
        return res;
    }
};