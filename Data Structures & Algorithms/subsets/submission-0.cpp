class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>current, int i, bool include){
        if (include){
            current.push_back(nums[i]);
        }
        else{
        }
        if (i == nums.size()-1){
            result.push_back(current);
        }
        if (i + 1 < nums.size()){
            backtrack(nums, current, i + 1, true);
            backtrack(nums, current, i + 1, false);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, current, 0, true);
        backtrack(nums, current, 0, false);
        return result;
    }
};
