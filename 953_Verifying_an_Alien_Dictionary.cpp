class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        int t = 0;
        for (int i = 0; i < order.length(); i++) {
            m[order[i]] = t++;
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            if (m[word1[0]] > m[word2[0]]) {
                return false;
            }
            else if (m[word1[0]] < m[word2[0]]) {
                continue;
            }
            else {
                int j = 0;
                while (j < min(word1.length(), word2.length())) {
                    if (m[word1[j]] == m[word2[j]]) {
                        j++;
                    }
                    else if (m[word1[j]] < m[word2[j]]) {
                        break;
                    }
                    else {
                        return false;
                    }
                }
                if (j == word1.length()) {
                    continue;
                }
                else if (j == word2.length()) {
                    if (j < word1.length())
                        return false;
                }
                else {
                    continue;
                }
            }
        }
        
        return true;
    }
};