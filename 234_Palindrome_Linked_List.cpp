/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void checkPalindrome(ListNode* &head, ListNode* tail, bool& ans) {
        if (tail == NULL)
            return;
        checkPalindrome(head, tail->next, ans);
        if (head->val != tail->val)
            ans = false;
        head = head->next;
    }
    
    bool isPalindrome(ListNode* head) {
        // Time- O(n)
        // Space- O(1)
        bool ans = true;
        
        checkPalindrome(head, head, ans);
        
        return ans;
        
        /*
        // Time- O(n)
        // Space- O(n)
        vector<int> arr;
        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for (int i = 0, j = n-1; i < j; i++, j--) {
            if (arr[i] != arr[j])
                return false;
        }
        return true;
        */
    }
};