class Solution {
public:
    string removeDuplicates(string s, int k) {
        int cnt = 1;
        bool flag = true;
        while (flag) {
            bool flag2 = false;
            cnt = 1;
            for (int i = 0; i < s.length()-1; i++) {
                if (s[i] == s[i+1])
                    cnt++;
                else
                    cnt = 1;
                if (cnt == k) {
                    flag2 = true;
                    s.erase(s.begin() + i - (k - 2), s.begin() + i + 2);
                    break;
                }
            }
            if (flag2 == false)
                flag = false;
        }
        //cout << s << endl;
        return s;
    }
};