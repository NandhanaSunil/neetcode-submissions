class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> numset;
        unordered_set <int> starts;
        for(int n : nums){
            numset.insert(n);
        }
        for (int n : numset){
            if (numset.count(n-1) == 0) starts.insert(n);
        }
        int len = 0;
        int maxlen = 0;

        for (int n: starts){
            int curr = n;
            while (numset.count(curr)){
                len++;
                curr++;
            }

            if (maxlen < len) maxlen = len;
            len = 0;
        }
        return maxlen;
    }
};
