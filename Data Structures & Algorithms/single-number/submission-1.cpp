class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 1;
        for(int i : nums){
            num = num ^ i;
        }
        return num^1;
    }
};
