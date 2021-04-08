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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *temp1 = head, *temp2 = head;
        
        while (temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        
        sort(arr.begin(), arr.end());
        
        int i = 0;
        while (temp2 != NULL) {
            temp2->val = arr[i++];
            temp2 = temp2->next;
        }
        
        return head;
    }
};