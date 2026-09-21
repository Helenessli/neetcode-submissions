class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numSet) {
            // Only start counting if num is the beginning
            // of a consecutive sequence
            if (!numSet.count(num - 1)) {
                int length = 1;
                int current = num;

                while (numSet.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};