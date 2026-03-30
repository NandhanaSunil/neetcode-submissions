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
    int* findkth(TreeNode*root, int* k, int* res){
        if(root->left){
            findkth(root->left, k, res);
        }
        if(root){
            (*k)--;
            if(*k==0){
                *res = root->val;
                return res;
                }
        }
        if(root->right){
            if(*res != -1) return res;
            findkth(root->right, k, res);
        }
        return res;

    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        int f = k;
        int *r = findkth(root, &f, &res);
        return *r;
    }
};
