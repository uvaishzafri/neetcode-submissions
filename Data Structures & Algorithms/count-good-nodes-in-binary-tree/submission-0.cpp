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
    int res =0 ;
    void helper(TreeNode* root, int maximum){
        if(!root) return;
        if(root->val>=maximum) res+=1;
        helper(root->left, max(maximum, root->val));
        helper(root->right, max(maximum, root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root)
        helper(root, root->val);
        
        return res;
    }
};
