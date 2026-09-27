class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()<=2){
            return nums.size() == 2 ? max(nums[0],nums[1]) : nums[0];
        }
        vector<int> maxMoney(nums.size());
        maxMoney[0] = nums[0];
        maxMoney[1] = nums[1];
        for (int i = 2; i < nums.size(); i++){
            if (i-3 < 0){
                maxMoney[i] = maxMoney[i-2] + nums[i];
            }else{
                maxMoney[i] = max(maxMoney[i-2] + nums[i], maxMoney[i-3] + nums[i]);
            }
        }
        return max(maxMoney[nums.size()-1], maxMoney[nums.size()-2]);
    }
};
