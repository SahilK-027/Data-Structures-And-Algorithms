class Solution {
private:
    int solveSO(int n)
    {
        int prev2 = 1;
        int prev1 = 1;
        int curr = 0;
        for(int i = 2; i <= n; i++){
            curr = prev2+prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int climbStairs(int n) {
        return solveSO(n);
    }
};
