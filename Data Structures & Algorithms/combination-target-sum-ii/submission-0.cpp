class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>&candidates, vector<int>&cur, int i, int cursum, int tar){
        if(cursum == tar){
            res.push_back(cur);
            return;
            }
        if(cursum > tar) return;
        if(i==candidates.size()) return;
        cur.push_back(candidates[i]);
        int next = i+1;
        dfs(candidates, cur, next, cursum+candidates[i], tar);
        cur.pop_back();
        while(next<candidates.size() && candidates[next]==candidates[next-1])next++;
        dfs(candidates, cur, next, cursum, tar);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>cur;
        dfs(candidates, cur, 0, 0, target);
        return res;
    }
};
