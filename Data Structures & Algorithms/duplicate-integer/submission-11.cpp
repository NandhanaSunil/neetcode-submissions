class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int k : nums){
            if(seen.count(k)) {
                return true;
            }
            else{
                seen.insert(k);

            }
        }
        return false;
    }
};