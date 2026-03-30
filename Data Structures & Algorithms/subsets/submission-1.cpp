class Solution {
public:
    void dfs(int i, vector<vector<int>>&res, vector<int>&nums, vector<int>&subset){
        if(i==nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1, res, nums, subset);
        subset.pop_back();
        dfs(i+1, res, nums, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        dfs(0, res, nums, subset);
        return res;
    }
};
