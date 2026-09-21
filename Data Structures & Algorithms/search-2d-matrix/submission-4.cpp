class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if (matrix[mid][0] <= target) {
                top = mid + 1;
            }
            else {
                bottom = mid - 1;
            }
        }

        int row = bottom;
        if (row < 0) {
            return false;
        }
        int left = 0;
        int right = matrix[0].size()-1;
        int mid = -1;
        while (left <= right){
            mid = left + (right-left)/2;
            if (matrix[row][mid] == target){
                return true;
            }
            else if (matrix[row][mid] < target){
                left = mid + 1;
            }
            else if (matrix[row][mid] > target){
                right = mid -1;
            }
        }
        return false;
    }
};
