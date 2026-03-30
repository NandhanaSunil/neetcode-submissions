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
    int findheight(TreeNode* root){
        if(!root) return 0;
        int l = 1+findheight(root->left);
        int r = 1+findheight(root->right);
        if (l>r) return l;
        return r;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                res = max(res, (findheight(cur->left) + findheight(cur->right)));
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};
