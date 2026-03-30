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
    bool checkSub(TreeNode* subRoot, TreeNode* start){
        if (!subRoot || !start) return (!subRoot && !start);
        return (subRoot->val == start->val) && checkSub(subRoot->left, start->left) && checkSub(subRoot->right, start->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> main;
        main.push(root);
        while (!main.empty()){
            int s = main.size();
            for (int i=0; i<s; i++){
                TreeNode* cur = main.front();
                main.pop();
                if (cur->val == subRoot->val){
                    bool issub = checkSub(subRoot,cur);
                    if (issub) return true;
                }
                if (cur->left) main.push(cur->left);
                if (cur->right) main.push(cur->right);
            }
        }
        return false;
    }
};
