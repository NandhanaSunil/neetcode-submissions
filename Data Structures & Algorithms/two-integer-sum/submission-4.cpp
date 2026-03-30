class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        int i = 0;
        for (int n : nums){
            comp[n] = i;
            i++;
        }
        for (int i=0; i<nums.size(); i++){
            int req = target - nums[i];
            if (comp.count(req) && comp[req]!= i) return vector<int> ({i, comp[req]});
        }
        return vector<int> {};
    }
};
