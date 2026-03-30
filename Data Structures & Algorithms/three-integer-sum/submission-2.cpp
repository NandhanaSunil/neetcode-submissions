class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]> 0) break;
            if (i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;

            int tar = -nums[i];
            while(left < right){
                int sum = nums[left] + nums[right];

                if (sum ==tar) {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                }
                else if (sum < tar) left++;
                else right--;
            }
        }
        return res;
    }
};
