class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, 0);
        int one = 0;
        int two = 0;
        for(int i=2; i<=cost.size(); i++){
            dp[i] = min(one+cost[i-2], two+cost[i-1]);
            one = two;
            two = dp[i];
        }
        return dp[cost.size()];
    }
};
