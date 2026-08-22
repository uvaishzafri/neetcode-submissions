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
    bool isBalance = true;
    int diff(TreeNode* root){
       if(root){
        int left = diff(root->left);
        int right = diff(root->right);
        if(abs(left-right)>1) isBalance = false;
        return 1+ max(left, right);

       }
       return 0;
    }
    bool isBalanced(TreeNode* root) {
        diff(root);
        return isBalance;
    }
};
