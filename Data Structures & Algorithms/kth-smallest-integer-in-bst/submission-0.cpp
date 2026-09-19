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
    int kthSmallest(TreeNode* root, int k) {
       int count=0,res;
        inOrder(root,res,k,count);
        return res;
    }
    void inOrder(TreeNode* root,int &res , int k , int &count){
        if(!root)
        return ;
        inOrder(root->left,res,k,count);
        if(++count==k)
        {
            res=root->val;
            return;
        }
        inOrder(root->right,res,k,count);
    }
};