class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        int len = nums.size();
        for(int i=0; i<len; i++){
            comp[nums[i]] = i;
        }
        for(int i=0; i<len; i++){
           int compN = target - nums[i];
           if (comp.find(compN) != comp.end()){
            if (i!= comp[compN])return vector<int>({i, comp[compN]});
           }
        }
        return vector<int>({});
    }
};
