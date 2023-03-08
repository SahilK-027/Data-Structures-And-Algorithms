class Solution {
private: 
    int solve(int n){
        // Base case
        if(n == 0) return 0;

        // Initial answer
        int ans = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            // Answer will be minimum of ans, subproblems solution
            ans = min(ans, 1 + solve(n - i * i));
        }

        return ans;
    }
public:
    int numSquares(int n) {
        return solve(n);
    }
};
