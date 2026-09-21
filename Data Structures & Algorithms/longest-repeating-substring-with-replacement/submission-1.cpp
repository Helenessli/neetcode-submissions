class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        unordered_map<char, int> window;
        int maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;

            maxFreq = 0;
            for (auto& pair : window) {
                maxFreq = max(maxFreq, pair.second);
            }

            while ((right - left + 1) - maxFreq > k) {
                window[s[left]]--;
                left++;

                // Recompute actual max frequency
                maxFreq = 0;
                for (auto& pair : window) {
                    maxFreq = max(maxFreq, pair.second);
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};