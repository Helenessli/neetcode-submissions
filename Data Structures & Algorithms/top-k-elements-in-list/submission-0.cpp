class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto n : nums){
            hash[n]++;
        }
        priority_queue<pair<int, int>>maxHeap;
        for (auto p : hash){
            maxHeap.push({p.second, p.first});
        }
        vector<int> answer;
        for (int i = 0; i < k; i++){
            answer.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return answer;
    }
};
