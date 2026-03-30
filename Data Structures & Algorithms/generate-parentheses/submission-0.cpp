class Solution {
public:
    vector<string>res;
    bool isvalid(string s){
        int open = 0;
        for(char c: s){
            if(c=='(') open++;
            else open--;
            if(open<0) return false;
        }
        return open==0;
    }

    void dfs(string s, int n){
        if(s.size() == 2*n){
            if(isvalid(s)) res.push_back(s);
            return;
        }
        dfs(s+'(', n);
        dfs(s+')', n);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n);
        return res;
    }
};
