class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsmap;

        for(int i=0; i<nums.size(); i++){
            numsmap[target - nums[i]] = i; 
        }

        for(int i=0; i<nums.size(); i++){
            if(numsmap.find(nums[i]) != numsmap.end() && i!= numsmap[nums[i]]){
                return {min(i, numsmap[nums[i]]), max(i, numsmap[nums[i]])};
            }
        }
        return vector<int> {};
    }
};
