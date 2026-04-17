class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numset (nums.begin() , nums.end());
        return numset.size() != nums.size();
    }
};