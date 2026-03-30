class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo1(nums.size(), 0);
        vector<int>memo2(nums.size(), 0);

        if(nums.size()== 1) return nums[0];
        if(nums.size()== 2) return max(nums[0], nums[1]);
        if(nums.size()== 3) return max(nums[0], max(nums[1], nums[2]));

        memo1[0] = nums[0];
        memo1[1] = max(nums[1], nums[0]);
        memo2[1] = nums[1];
        memo2[2] = max(nums[2], nums[1]);
        for(int i=2; i<nums.size()-1; i++){
            memo1[i] = max(nums[i] + memo1[i-2], memo1[i-1]);
            // cout << memo1[i] << endl;
        }

        for(int i=3; i<nums.size(); i++){
            memo2[i] = max(nums[i] + memo2[i-2], memo2[i-1]);
            // cout << memo2[i];
        }

        return max(memo1[nums.size()-2], memo2[nums.size()-1]);
    }
};
