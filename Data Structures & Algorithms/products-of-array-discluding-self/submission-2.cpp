class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         unordered_map <int, int> back;
         unordered_map <int, int> front;
         
        int bp = 1;
        int fp = 1;

        for (int i=0; i<nums.size(); i++){
            back[i] = bp;
            bp *= nums[i];
        }
        for (int i=nums.size()-1; i>=0; i--){
            front[i] = fp;
            fp *= nums[i];
        }

        vector <int> res;
        for (int i =0; i<nums.size(); i++){
            // cout << num << " " << back[num] << " " << front[num]<< endl;
            res.push_back(back[i]*front[i]);
        }
        return res;
    }
};
