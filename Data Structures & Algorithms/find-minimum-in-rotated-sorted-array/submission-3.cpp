class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            int leftnum = mid == 0 ? nums[n-1] : nums[mid - 1];
            int rightnum = mid == n-1 ? nums[0] : nums[mid + 1];
            if (nums[mid] <= rightnum && nums[mid] <= leftnum) return nums[mid];
            else {
                bool rotated = nums[right] < nums[mid];
                if (rotated){
                    left = mid + 1;
                }
                else {
                   right = mid - 1;
                }
            }
        }
        return -1;
    }
};
