class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, vector<int>&candidates, int target, vector<int>&subset, int cursum){
        if(cursum == target){
            res.push_back(subset);
            return;
        }
        if(i>=candidates.size()) return;
        if (cursum > target) return;
        // for(int j=i; j<candidates.size(); j++){
            
        // }
        subset.push_back(candidates[i]);
        dfs(i+1, candidates, target, subset, cursum+candidates[i]);
        subset.pop_back();
        while(i+1<candidates.size() && candidates[i+1] == candidates[i]) i++;
        dfs(i+1, candidates, target, subset, cursum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>subset;
        dfs(0, candidates, target, subset, 0);
        return res;
    }
};
