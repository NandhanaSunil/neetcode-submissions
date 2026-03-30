class Solution {
public:
    int dfs(vector<int>&cost, vector<int>&memo, int i){
        if(i>=cost.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i] = cost[i]+ min(dfs(cost, memo, i+1), dfs(cost, memo, i+2));
        return memo[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>memo(cost.size(), -1);
        return min(dfs(cost, memo, 0), dfs(cost, memo, 1));
    }
};
