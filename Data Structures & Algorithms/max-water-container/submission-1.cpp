class Solution {
public:
    int maxArea(vector<int>& heights) {
        int w = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l<r){
            w = max(w, (r-l)*(min(heights[l], heights[r])));
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return w;
    }
};
