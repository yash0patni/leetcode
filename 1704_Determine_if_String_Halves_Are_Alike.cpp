class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U');
    }
    
    bool halvesAreAlike(string s) {
        int aCount = 0;
        int bCount = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                if (i < n/2)
                    aCount++;
                else
                    bCount++;
            }
        }
        
        return aCount == bCount;
    }
};