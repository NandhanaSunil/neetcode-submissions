class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tarmap;
        for(int i = 0; i<nums.size(); i++){
            tarmap[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            int t = target - nums[i];
            if(tarmap.find(t) != tarmap.end() && i!=tarmap[t]){
                return vector<int>{min(i, tarmap[t]), max(i, tarmap[t])};
            }
        }
        return vector<int> {};
    }
};
