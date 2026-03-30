class Solution {
public:
    vector<string> res;
    bool isvalid(string par){
        int c = 0;
        for(char p : par){
            if(p == '(') c++;
            else c--;
            if(c<0) return false;
        }
        return c==0;
    }
    void dfs(int i, int n, string par){
        if(i==2*n && isvalid(par)){
            res.push_back(par);
            return;
        }
        if (i>=2*n) return;
        dfs(i+1, n, par + '(');
        dfs(i+1, n, par + ')');
    }
    vector<string> generateParenthesis(int n) {
        dfs(0, n, "");
        return res;
    }
};
