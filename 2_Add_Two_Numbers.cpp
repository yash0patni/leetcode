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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        ListNode* temp = l1;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            l1->val = sum;
            
            temp = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            l1->val = sum;
            
            temp = l1;
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            l2->val = sum;
            //l1 = temp;
            temp->next = l2;
            temp = temp->next;
            
            l2 = l2->next;
        }
        
        
        if (carry > 0) {
            ListNode* last = new ListNode(carry);
            temp->next = last;
        }
        
        return res;
    }
};