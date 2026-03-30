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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> st;
        if(root) st.push(root);
        string res = "";
        while(!st.empty()){
            int n = st.size();
            for(int i=0; i<n; i++){
                TreeNode* cur = st.front();
                st.pop();
                if (cur){
                    res += to_string(cur->val) + ',';
                    if(cur->left) st.push(cur->left);
                    else st.push(nullptr);

                    if (cur->right) st.push(cur->right);
                    else st.push(nullptr);
                }
                else{
                    res += "-,";
                }
            }
        }
        cout << res << endl;
        return res == "" ? "" : res.substr(0, res.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data == "") return nullptr;
        int i = 0;
        queue<TreeNode*> st;
        int start = i;
        while(i<data.size() && data[i] != ','){i++;}
        string sval = data.substr(start, i-start);
        TreeNode* root = sval == "-" ? nullptr : new TreeNode(stoi(sval));
        st.push(root);
        while (!st.empty() && i<data.size()){
            int n = st.size();

            for(int j = 0; j<n; j++){
                TreeNode* cur = st.front();
                st.pop();
                i++;
                start = i;
                while(i<data.size() && data[i] != ',') i++;
                sval = data.substr(start, i-start);
                cur->left = sval == "-" ? nullptr : new TreeNode(stoi(sval));
                i++;
                start = i;
                while(i<data.size() && data[i] != ',') i++;
                sval = data.substr(start, i-start);
                cur->right = sval == "-" ? nullptr : new TreeNode(stoi(sval));
                if(cur->left) st.push(cur->left);
                if(cur->right) st.push(cur->right);
            }
        }

        return root;
    }
};
