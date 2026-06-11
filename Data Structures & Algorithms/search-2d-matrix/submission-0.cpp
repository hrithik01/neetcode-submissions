class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l=0, r=m-1, ansrow = 0;
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                ansrow = mid;
                break;
            } else if(target > matrix[mid][n-1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0;
        r = n-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(matrix[ansrow][mid] == target) return true;
            else if(matrix[ansrow][mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
