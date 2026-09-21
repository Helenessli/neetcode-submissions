class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        unordered_map<char, int> window;
        int maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;

            maxFreq = max(maxFreq, window[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                window[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};