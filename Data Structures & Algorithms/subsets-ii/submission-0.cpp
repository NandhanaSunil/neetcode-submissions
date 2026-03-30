class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>&nums, int i, vector<int>&cur){
        if(i==nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums, i+1, cur);
        cur.pop_back();
        while(nums[i+1] == nums[i])i++;
        dfs(nums, i+1, cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>cur;
        dfs(nums, 0, cur);
        return res;
    }
};
