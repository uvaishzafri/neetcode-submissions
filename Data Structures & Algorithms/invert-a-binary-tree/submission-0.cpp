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
    pair<TreeNode*, TreeNode*> swapper(TreeNode* left, TreeNode* right) {
        if(left&&right)
        cout << left->val << " " << right->val << endl;
        if (left) {
            pair<TreeNode*, TreeNode*> result = swapper(left->left, left->right);
            left->left = result.second;
            left->right = result.first;
        }
        if (right) {
            pair<TreeNode*, TreeNode*> result = swapper(right->left, right->right);
            right->left = result.second;
            right->right = result.first;
        }
        return {left, right};
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            pair<TreeNode*, TreeNode*> result = swapper(root->left, root->right);
            root->left = result.second;
            root->right = result.first;
        }
        return root;
    }
};
