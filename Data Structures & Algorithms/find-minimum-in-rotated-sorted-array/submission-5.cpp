class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left + (right -left)/2;
            int leftnum = mid == 0? nums[n-1] : nums[mid - 1];
            int rightnum = mid == n-1 ? nums[0] : nums[mid + 1];

            cout << leftnum << " " << rightnum << endl;
            if (nums[mid] <= leftnum && nums[mid] <= rightnum) return nums[mid];
            bool isinright = nums[right] < nums[mid]; 
            if (isinright) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
