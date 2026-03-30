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
        int l = 1 + findheight(root->left);
        int r = 1 + findheight(root->right);
        if (l>r) return l;
        return r;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* cur = q.front();
                q.pop();
                int l = findheight(cur->left);
                int r = findheight(cur->right);
                if (abs(l-r) > 1) return false;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        } 
        return true;
    }
};
