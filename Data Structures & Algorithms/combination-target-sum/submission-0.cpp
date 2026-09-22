class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& current, int target, int i) {
        // We found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // We went past the target
        if (target < 0 || i == nums.size()) {
            return;
        }

        // Include nums[i]
        current.push_back(nums[i]);
        backtrack(nums, current, target - nums[i], i);

        // Don't include nums[i]
        current.pop_back();
        backtrack(nums, current, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtrack(nums, current, target, 0);
        return result;
    }
};