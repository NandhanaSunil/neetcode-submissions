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
    int findn(TreeNode* node, int maxval){
        if (!node) return 0;
        else if (node->val >= maxval){
            maxval = max(maxval, node->val);
            return 1 + findn(node->left, maxval) + findn(node->right, maxval);
        }
        else return 0 + findn(node->left, maxval) + findn(node->right, maxval);
    }
    int goodNodes(TreeNode* root) {
        return 1 + findn(root->left, root->val) + findn(root->right, root->val);
    }
};
