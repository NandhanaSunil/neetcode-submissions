class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targetIndex (nums.size());
        for (int i=0; i<nums.size(); i++){
            targetIndex[target - nums[i]] = i;
        }

        for (int j=0; j<nums.size(); j++){
            int t = target - nums[j];
            if (targetIndex.find(nums[j]) != targetIndex.end())   
            {
                int i = targetIndex[nums[j]];
                if (i != j){
                    vector<int> res = {j, i};
                sort( res.begin(), res.end()                );
                return res;
                }
                
            }
        }
        return vector<int>(2, 0);
    }
};
