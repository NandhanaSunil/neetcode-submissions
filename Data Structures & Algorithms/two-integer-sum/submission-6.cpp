class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tarmap;
        for(int i=0; i< nums.size(); i++){
            int comp = target - nums[i];
            tarmap[comp] = i;
        }
        for(int i = 0; i<nums.size(); i++){
            if(tarmap.find(nums[i]) != tarmap.end() && i!=tarmap[nums[i]]){
                return (vector<int> ({min(i, tarmap[nums[i]]), max(i, tarmap[nums[i]])}));
            }
        }
        return vector<int> ({0,0});
    }
};
