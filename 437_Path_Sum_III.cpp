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
    void checkRoot(TreeNode* root, int sum, int curSum, int& paths) {
        if (!root) return;
        if (curSum == sum)
            paths++;
        if (root->left)
            checkRoot(root->left, sum, curSum+root->left->val, paths);
        if (root->right)
            checkRoot(root->right, sum, curSum+root->right->val, paths);
    }
    
    void checkEachRoot(TreeNode* root, int sum, int& paths) {
        if (!root) return;
        checkRoot(root, sum, root->val, paths);
        checkEachRoot(root->left, sum, paths);
        checkEachRoot(root->right, sum, paths);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int paths = 0;
        
        checkEachRoot(root, sum, paths);
        
        return paths;
    }
};