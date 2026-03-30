class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int m = *max_element(piles.begin(), piles.end());
        int res = 1;
        while (l<=m){
            long long total = 0;
            int mid = l + (m-l)/2;
            for (int p : piles){
                total += ceil(((double)p)/mid);
            }
            if (total <= h){
                res = mid;
                m = mid-1;
            }
            else {
                l = mid + 1;
            }
            
        }
        return res;
    }
};
