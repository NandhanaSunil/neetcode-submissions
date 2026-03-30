class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map <int, int> forward_prod;
        unordered_map <int, int> backward_prod;
        
        int fp = 1;
        int bp = 1;
        
        int len = nums.size();

        for(int i=0; i<len-1; i++){
            fp *= nums[i];
            forward_prod[i+1] = fp;
        }
        forward_prod[0] = 1;
        for(int i=len-1; i>0; i--){
            bp *= nums[i];
            backward_prod[i-1] = bp;
        }
        backward_prod[len-1] = 1;

        vector<int> res;
        for(int i=0; i<len; i++){
            res.push_back(forward_prod[i] * backward_prod[i]);
        }
        return res;
    }
};
