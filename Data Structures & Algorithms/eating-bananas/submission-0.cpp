class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int k = left + (right - left) / 2;

            int hours = 0;

            for (int pile : piles) {
                hours += (pile + k - 1) / k;
            }

            if (hours <= h) {
                // k works, but maybe we can go slower
                right = k - 1;
            }
            else {
                // k is too slow
                left = k + 1;
            }
        }

        return left;
    }
};