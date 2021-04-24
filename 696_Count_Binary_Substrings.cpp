class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        int count0 = 0;
        int count1 = 0;
        
        while (i < n) {
            if (s[i] == '0') {
                while (i < n && s[i] == '0') {
                    count0++;
                    i++;
                }
                ans += min(count0, count1);
                count1 = 0;
            } else {
                while (i < n && s[i] == '1') {
                    count1++;
                    i++;
                }
                ans += min(count0, count1);
                count0 = 0;
            }
        }
        
        return ans;
    }
};