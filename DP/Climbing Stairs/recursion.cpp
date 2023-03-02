class Solution {
public:
    int climbStairs(int n) {
        // if we reached the ground
        if( n == 0 ){
            return 1;
        }
        // If the path doesn't take us to ground
        if( n < 0 ){
            return 0;
        }

        // Return the path which we get by climbing 
        return climbStairs(n-1) + climbStairs(n - 2);
    }
};
