class Solution {
public:
    int trap(vector<int>& height) {
       int l = 0;
       int r = height.size() - 1;
       while (l<=r && height[l] == 0) l++;
       while (r>l && height[r]== 0) r--;
       if (r-l < 2) return 0;

       unordered_map <int, int> prefix;
       unordered_map <int, int> suffix;

       int premax = height[l];

       for(int i =l+1; i<r; i++){
            prefix[i] = premax;
            premax = max(premax, height[i]);
       } 

       int sufmax = height[r]; 
       for(int i= r-1; i>l; i--){
        suffix[i] = sufmax;
        sufmax = max(sufmax, height[i]);
       }
       int water = 0;
       for (int i=l+1; i<r; i++){
        int w = min(prefix[i], suffix[i]) - height[i];
        // cout << i << " pre :" << prefix[i] << " suf :" << suffix[i] << " w:" << w << endl;
        if (w>=0) water += w;
       }
       return water;
    }
};
