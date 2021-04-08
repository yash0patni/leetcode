class Solution {
public:
    map<int, string> s;
    
    vector<string> letterCombinations(string digits) {
        s[1] = " ";
        s[2] = "abc";
        s[3] = "def";
        s[4] = "ghi";
        s[5] = "jkl";
        s[6] = "mno";
        s[7] = "pqrs";
        s[8] = "tuv";
        s[9] = "wxyz";
        
        /*vector<string> ans;
        string str = "";
        
        vector<int> d(4);
        for (int i = 0; i < digits.length(); i++) {
            d[i] = digits[i] - '0';
        }
        for (int i = digits.length(); i < 4; i++) {
            d[i] = 1;
        }
        
        for (int i = 0; i < s[d[0]].length(); i++) {
            if (s[d[0]][i] != ' ') str.push_back(s[d[0]][i]);
            for (int j = 0; j < s[d[1]].length(); j++) {
                if (s[d[1]][j] != ' ') str.push_back(s[d[1]][j]);
                for (int k = 0; k < s[d[2]].length(); k++) {
                    if (s[d[2]][k] != ' ') str.push_back(s[d[2]][k]);
                    for (int l = 0; l < s[d[3]].length(); l++) {
                        if (s[d[3]][l] != ' ') str.push_back(s[d[3]][l]);
                        if (str.length() > 0)
                            ans.push_back(str);
                        if (s[d[3]][l] != ' ') str.pop_back();
                    }
                    if (s[d[2]][k] != ' ') str.pop_back();
                }
                if (s[d[1]][j] != ' ') str.pop_back();
            }
            if(s[d[0]][i] != ' ') str.pop_back();
        }*/
        
        vector<string> ans;
        if (digits.length() == 0) return ans;
        ans.push_back("");
        
        for (int i = 0; i < digits.length(); i++) {
            int d = digits[i] - '0';
            string str = s[d];
            vector<string> tempAns;
            for (int j = 0; j < str.length(); j++) {
                for (int k = 0; k < ans.size(); k++) {
                    tempAns.push_back(ans[k] + str[j]);
                }
            }
            ans = tempAns;
        }
        
        return ans;
    }
};