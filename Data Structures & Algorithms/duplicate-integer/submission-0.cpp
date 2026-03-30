class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> dupmap;
        int len = nums.size();
        for (int i=0; i<len; i++){
            dupmap[nums[i]] = INT_MIN;
        }
        for (int i=0; i<len; i++){
           if (dupmap[nums[i]] == INT_MIN){
             dupmap[nums[i]] = 1;
           }
           else {
            return true;
           }
        }
        return false;
    }
};