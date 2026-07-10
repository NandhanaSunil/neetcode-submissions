class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prev_prod (nums.size(), 1);
        vector<int> forward_prod (nums.size(), 1);
        for(int i=0; i<nums.size()-1; i++){
            prev_prod[i+1] = prev_prod[i]*nums[i];
        }

        for(int i=nums.size()-2; i>=0; i--){
            forward_prod[i] = forward_prod[i+1]*nums[i+1];
        }
        vector<int> res(nums.size());
        for(int i= 0; i<nums.size(); i++){
            res[i] = prev_prod[i] * forward_prod[i];
        }

        return res;
    }
};
