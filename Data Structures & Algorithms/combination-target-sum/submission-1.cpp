class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>&nums, vector<int>&sub, int i, int currsum, int t){
        if(i>=nums.size() || currsum>t)return;
        if(currsum == t) res.push_back(sub);
        if((currsum + nums[i]) > t)return;
        sub.push_back(nums[i]);
        dfs(nums, sub, i, currsum+nums[i], t);
        sub.pop_back();
        dfs(nums, sub, i+1, currsum, t);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>sub;
        dfs(nums, sub, 0, 0, target);
        return res;

    }
};
