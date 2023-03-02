class Solution {
private:
    int solve(vector<int>& cost, int n){
        if( n == 0 ){
            return cost[n];
        }
        if( n < 0){
            return 0;
        }
        return min(solve(cost, n-1) + cost[n], solve(cost, n-2) + cost[n]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return  min(solve(cost, n-1), solve(cost, n-2));
    }
};
