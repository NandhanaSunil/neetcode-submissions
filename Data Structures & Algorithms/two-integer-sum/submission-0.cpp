class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> difference_map;
        for(int i=0; i<nums.size(); i++){
            difference_map[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            int num1 = target - nums[i];
            if (difference_map.find(num1) != difference_map.end() && difference_map[num1] != i){
                return {i, difference_map[num1]};
            }
        }
        return {};
    }
};
