class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1){
            return 0;
        }

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minPrefix = 0;
        int maxSum = nums[0];

        for (int i = 1; i <= n; i++) {
            maxSum = max(maxSum, prefix[i] - minPrefix);
            minPrefix = min(minPrefix, prefix[i]);
        }

        return maxSum;
    }
};