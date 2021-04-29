/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*
        // Time- O(N) | Space- O(N)
        set<ListNode*> vis;
        while (head != NULL) {
            if (vis.find(head) == vis.end()) {
                vis.insert(head);
            }
            else {
                return head;
            }
            head = head->next;
        }
        return NULL;
        */
        
        // Time- O(N) | Space- O(1)
        // Explanation- https://www.youtube.com/watch?v=QfbOhn0WZ88
        if (!head || !head->next)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (slow == fast) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }
};