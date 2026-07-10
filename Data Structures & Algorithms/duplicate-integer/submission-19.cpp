class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numset = unordered_set<int>(nums.begin(), nums.end());
        return numset.size() != nums.size(); 
    }
};