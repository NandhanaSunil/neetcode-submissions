class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numset;
        for(int i: nums){
            if(numset.find(i) != numset.end()) return true;
            numset.insert(i);
        }
        return false;
    }
};