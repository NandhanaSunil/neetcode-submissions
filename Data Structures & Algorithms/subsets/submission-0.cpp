class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>&nums, vector<int>&subset, int i){
        if(i == nums.size()) {
            res.push_back(subset);
            return;
            }
        subset.push_back(nums[i]);
        dfs(res, nums, subset, i+1);
        subset.pop_back();
        dfs(res, nums, subset, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, nums, subset, 0);
        return res;
    }
};
