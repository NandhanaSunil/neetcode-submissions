class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        while(cur<nums.size() && dp[cur]){
            int s = nums[cur];
            for(int i=1; i<=s; i++){
                dp[cur + i] = true;
            }
            cur += 1;
        }
        return dp[nums.size()-1];
    }
};
