class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return vector<int> {};

        int ind = 0;
        int m = nums[0];
        for (int i = 0; i <k; i++){
            if (m < nums[i]){
                ind = i;
                m = nums[i];
                }
        }

        vector<int> res {m};

        for (int i=1; i<=nums.size()-k; i++){
            if(ind < i){
                m = nums[i];
                for(int j= i; j<i+k; j++){
                    if(m < nums[j]){
                        m = nums[j];
                        ind = j;
                    }
                }
                res.push_back(m);

            }
            else{
                if (nums[i+k-1] > nums[ind]){
                    res.push_back(nums[i+k-1]);
                    ind = i;
                }
                else res.push_back(nums[ind]);
            }
            cout << i << " " << ind << " " << res[i] << endl;
        }
        return res;
    }
};
