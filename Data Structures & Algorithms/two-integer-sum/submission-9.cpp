class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tgts;
        for(int i=0; i<nums.size(); i++){
            if(tgts.find(nums[i]) != tgts.end()) return {tgts[nums[i]], i};
            else tgts[target - nums[i]] = i;
        }
        return {};
    }
};
