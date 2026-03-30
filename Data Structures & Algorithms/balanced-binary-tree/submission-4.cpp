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
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            for (int i=0; i<n; i++){
                int l = 0;
                int r = 0;
                TreeNode* cur = q.front();
                cout << cur->val;
                q.pop();
                if(cur->left){
                    l = findheight(cur->left);
                    q.push(cur->left);
                }
                if(cur->right){
                    r = findheight(cur->right);
                    q.push(cur->right);
                }
                cout << " : " << l << " : " << r << endl;
                if(abs(l-r) > 1) return false;
            }
        }
        return true;
    }
};
