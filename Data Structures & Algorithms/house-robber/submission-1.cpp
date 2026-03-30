class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(), 0);
        if(nums.size()== 1) return nums[0];
        if(nums.size()== 2) return max(nums[0], nums[1]);

        memo[0] = nums[0];
        memo[1] = max(nums[1], nums[0]);

        for(int i=2; i<nums.size(); i++){
            memo[i] = max(nums[i] + memo[i-2], memo[i-1]);
        }

        return max(memo[nums.size()-2], memo[nums.size()-1]);
    }
};
