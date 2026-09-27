class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1){
            return 0;
        }
        vector<int> minCost(cost.size()+2, 0);
        minCost[0] = 0;
        minCost[1] = 0;
        for (int i = 2; i < cost.size()+1; i++){
            minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2]);
        }
        return minCost[cost.size()];

    }
};
