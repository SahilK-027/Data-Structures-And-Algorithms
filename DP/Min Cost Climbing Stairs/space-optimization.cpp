class Solution {
private:
    int solveSO(vector<int>& cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr = 0;
        for(int i = 2 ; i <= n; i++){
            curr = min(prev2 + cost[i], prev1 + cost[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2){
            return min(cost[1], cost[0]);
        }
        return  min(solveSO(cost, n-1), solveSO(cost, n-2));
    }
};
