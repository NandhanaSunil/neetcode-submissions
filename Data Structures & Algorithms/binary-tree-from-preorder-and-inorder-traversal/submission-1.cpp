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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || preorder.empty()) return nullptr;
        TreeNode* cur = new TreeNode(preorder[0]);
        auto idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> preorderleft (preorder.begin()+1, preorder.begin() + idx + 1);
        vector<int> preorderright (preorder.begin() + idx + 1, preorder.end());

        vector<int> inorderleft (inorder.begin(),  inorder.begin() + idx);
        vector<int> inorderright (inorder.begin() + idx + 1, inorder.end());

        cur -> left = buildTree(preorderleft, inorderleft);
        cur -> right = buildTree(preorderright, inorderright);

        return cur;
    }
};
