/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> levels;
        //levels.push_back({root->val});
        
        q.push({root, 1});
        int sum = 0;
        
        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (levels.size() == level) {
                levels[level-1].push_back(temp->val);
            } else {
                levels.push_back({temp->val});
            }
            
            if (temp->left) {
                q.push({temp->left, level+1});
            }
            if (temp->right) {
                q.push({temp->right, level+1});
            }
        }
            
        for (int val : levels[levels.size()-1])
            sum += val;
        
        return sum;
    }
};