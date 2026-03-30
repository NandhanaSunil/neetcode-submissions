class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p = 0;
        int one = 0;
        int two = 0;
        for(int i=2; i<=cost.size(); i++){
            p = min(one+cost[i-2], two+cost[i-1]);
            one = two;
            two = p;
        }
        return p;
    }
};
