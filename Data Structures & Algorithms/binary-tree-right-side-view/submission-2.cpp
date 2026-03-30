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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)q.push(root);
        vector<int> res;
        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n-1; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            TreeNode* rightnode = q.front();
            q.pop();
            res.push_back(rightnode->val);
            if(rightnode->left)q.push(rightnode->left);
            if(rightnode->right)q.push(rightnode->right);
        }
        return res;
    }
};
