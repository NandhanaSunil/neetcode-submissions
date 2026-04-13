class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tgtpairs;
        for(int i=0; i<nums.size(); i++){
            int t = target - nums[i];
            tgtpairs[t] = i;
        }
        for(int i=0; i<nums.size(); i++){
            if(tgtpairs.find(nums[i]) != tgtpairs.end() && i!= tgtpairs[nums[i]]) 
            return {min(i, tgtpairs[nums[i]]), max(i, tgtpairs[nums[i]])};
        }
        return {0,0};
    }
};
