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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //pop q
        //parse q
        //add child left to right
        vector<vector<int>> res;
        if (!root) return res;

        std::queue<pair<TreeNode*, int>>  q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [c, lvl] = q.front();
            q.pop();
            if (res.size() != lvl+1) {
                res.push_back({c->val});
            } else {
                res[lvl].push_back(c->val);
            }

            if (c->left) {     
                q.push({c->left, lvl+1});
            }
            if (c->right) {      
                q.push({c->right, lvl+1});
            }
            
        }
      return res;
    }
};