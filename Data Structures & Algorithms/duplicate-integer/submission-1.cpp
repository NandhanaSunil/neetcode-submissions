class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len  = nums.size();
        unordered_set<int> seen;
        for (int i=0; i<len; i++){
            if (seen.find(nums[i]) != seen.end()){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};