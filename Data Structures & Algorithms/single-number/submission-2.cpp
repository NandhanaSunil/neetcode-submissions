class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0];
        for(int n : nums) x = x ^ n;
        return x ^ nums[0];
    }
};
