class Solution {
private:
    int tabulation(vector<int>& obs){
        int n = obs.size()-1;
        vector<vector<int>> dp(3+1, vector<int>(obs.size(), 1000000));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int currLane =1; currLane <= 3; currLane++){
                // check next position in same lane
                if(obs[currPos + 1] != currLane) dp[currLane][currPos] = dp[currLane][currPos+1];

                // Side ways jump
                else{
                    int minJumps = 1000000;
                    for(int i = 1; i <= 3; i++){
                        // Jump in lane only if it is not curr lane
                        if(currLane != i){
                            // Jump in lane only it does not has obstacle
                            if(obs[currPos] != i){
                                minJumps = min(minJumps, 1+ dp[i][currPos+1]);
                            }
                        }
                    }
                    dp[currLane][currPos] = minJumps;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0] , 1 + dp[3][0]));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return tabulation(obstacles);
    }
};
