class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int i, vector<int>&nums, int target, int cursum, vector<int>&subset){
        if(cursum == target){
            res.push_back(subset);
            return;
        }
        if(cursum > target || i>=nums.size()){
            return;
        }
        subset.push_back(nums[i]);
        backtrack(i, nums, target, cursum+nums[i], subset);
        subset.pop_back();
        backtrack(i+1, nums, target, cursum, subset);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        backtrack(0, nums, target, 0, subset);
        return res;
    }
};
