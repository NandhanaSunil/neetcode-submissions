class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval = nums[0];
        int curmin = nums[0];
        int curmax = nums[0];
        for(int i=1; i<nums.size(); i++){
            curmax = max(max(curmax + nums[i], curmin + nums[i]), nums[i]);
            curmin = min(min(curmin + nums[i], curmax + nums[i]), nums[i]);
            maxval = max(maxval, curmax);
        }
        return maxval;
    }
};
