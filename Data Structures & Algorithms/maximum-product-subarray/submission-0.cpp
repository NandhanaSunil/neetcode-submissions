class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int maxval = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) dp[i][j] = nums[i];
                else dp[i][j] = dp[i][j-1]*nums[j];
                maxval = max(dp[i][j], maxval);
            }
        }
        return maxval;
    }
};
