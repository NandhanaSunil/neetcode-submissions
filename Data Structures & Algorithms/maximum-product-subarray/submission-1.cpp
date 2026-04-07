class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int maxval = INT_MIN;
        for(int i=0; i<n; i++){
            int prod = nums[i];
            for(int j=i; j<n; j++){
                if(i!=j) prod = prod * nums[j];
                // cout << i << " " << j << " " << prod << endl;
                maxval = max(prod, maxval);
            }
        }
        return maxval;
    }
};
