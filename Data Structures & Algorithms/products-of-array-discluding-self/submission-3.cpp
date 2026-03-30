class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> backprod;
        int prod = 1;
        for(int i : nums){
            backprod.push_back(prod);
            prod *= i;
        }

        vector<int>forward(nums.size());
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--){
            forward[i] = prod;
            prod*=nums[i];
        }

        vector<int> res;
        int i =0;
        while(i<nums.size()){
            res.push_back(backprod[i]*forward[i]);
            i++;
        }
        return res;
    }
};
