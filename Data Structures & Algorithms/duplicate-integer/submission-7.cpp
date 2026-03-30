class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool answer = false;
        int sizee = nums.size();
        for (int i = 0; i< sizee; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[j] == nums[i]) and (j!=i)) {
                    answer = true;
                    break;
                }
            }
        }
        return answer;
    }
};