class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sHash;
        unordered_map<char, int> tHash;
        for (auto c : s){
            sHash[c]++;
        }
        for (auto c : t){
            tHash[c]++;
        }
        return sHash == tHash;
    }
};
