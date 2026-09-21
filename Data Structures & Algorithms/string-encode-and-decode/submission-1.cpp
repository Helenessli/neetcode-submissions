class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            // Find the '#'
            while (s[j] != '#') {
                j++;
            }

            // Get the length of the string
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract the actual string
            string word = s.substr(j, len);
            result.push_back(word);

            // Move to the beginning of the next encoded string
            i = j + len;
        }

        return result;
    }
};