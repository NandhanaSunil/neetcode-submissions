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
    TreeNode* lca(TreeNode* root, int minval, int maxval){
        if(root == nullptr) return root;
        TreeNode* leftptr = nullptr;
        TreeNode* rightptr = nullptr;
        if(maxval < root->val){
            //lca in is root or in left of root
            leftptr = lca(root->left, minval, maxval);
        }
        else if (minval > root->val){
            //lca is root or in right of root
            rightptr = lca(root->right, minval, maxval);
        }
        else if (minval <= root->val && maxval >= root->val){
            leftptr = root;
        }
        if(leftptr != nullptr)return leftptr;
        else return rightptr;   
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;

        int maxval = max(pval, qval);
        int minval = min(pval, qval);

        TreeNode* anc = lca(root, minval, maxval);
        return anc;
        
    }
};
