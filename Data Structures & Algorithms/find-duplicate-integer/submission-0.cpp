class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++){
            int k = abs(nums[i]);
            if(nums[k -1] < 0) return k;
            else nums[k - 1] *= -1;
        }
    }
};
