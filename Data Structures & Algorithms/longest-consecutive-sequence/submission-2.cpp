class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sets (nums.begin(), nums.end());
        int maxlen = 0;
        for(int i:nums){
            if(sets.find(i-1) == sets.end()) {
                int k = 1;
                int start = i;
                while(sets.find(start+1) != sets.end()) {
                    k++;
                    start++;
                }
                maxlen = max(maxlen,k);
            }
        }
        return maxlen;
    }
};
