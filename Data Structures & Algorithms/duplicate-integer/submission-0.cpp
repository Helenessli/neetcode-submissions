class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (auto num : nums){
            hashmap[num]++;
            if (hashmap[num] != 1){
                return true;
            }
        }
        return false;
    }
};