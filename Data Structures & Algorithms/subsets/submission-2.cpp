class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, vector<int>&subset, vector<int>&nums){
        if(i==nums.size()) {
            res.push_back(subset);
            return;
            }
        subset.push_back(nums[i]);
        dfs(i+1, subset, nums);
        subset.pop_back();
        dfs(i+1, subset, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        dfs(0, subset, nums);
        return res;
    }
};
