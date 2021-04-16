/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        map<Node*,Node*> m;
        
        Node *ans, *temp;
        ans = new Node(0);
        temp = ans;
        while (head != NULL) {
            Node *t;
            if (m.find(head) == m.end()) {
                t = new Node(head->val);
                m[head] = t;
            }
            else
                t = m[head];
            temp->next = t;
            temp = temp->next;
            
            Node *hr = head->random;
            if (hr != NULL) {
                Node *rc;
                if (m.find(hr) == m.end()) {
                    rc = new Node(hr->val);
                    m[hr] = rc;
                }
                else
                    rc = m[hr];
                temp->random = rc;
            }
            
            head = head->next;
        }
        
        return ans->next;
    }
};