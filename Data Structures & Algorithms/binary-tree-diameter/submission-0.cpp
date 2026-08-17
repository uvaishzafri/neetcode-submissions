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
    int maximum = 0;
    int diameter(TreeNode* root) {
        if (root) {
            int left = diameter(root->left);
            int right = diameter(root->right);
            int subtree_max = left + right;
            maximum = max(maximum, subtree_max);
            cout << root->val << " " << left << " " << right << " " << maximum << endl;

            return 1 + max(left, right);
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);

        return maximum;
    }
};
