class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int rowsize = matrix[0].size();
        int colsize = matrix.size();
        int rstart = 0;
        int rend = colsize - 1;
        int midrow;
        bool found = false;
        while (rstart <= rend){
            midrow = rstart + (rend - rstart)/2;
            if (target >= matrix[midrow][0] && target <= matrix[midrow][rowsize-1]){
                found = true;
                cout << midrow << endl;
                break;
            }
            else if (target < matrix[midrow][0]){
                rend = midrow - 1;
            }
            else if (target > matrix[midrow][rowsize-1]){
                rstart = midrow + 1;
            }
        }
        if (found){
            vector <int> matrow = matrix[midrow];
            int l = 0;
            int r = rowsize - 1;
            int mid; 
            while (l<=r){
                mid = l + (r-l)/2;
                if (matrow[mid] == target){return true;}
                else if (matrow[mid] < target){l = mid+1;}
                else {r = mid - 1;}
            }
        }
        return false;
    }
};
