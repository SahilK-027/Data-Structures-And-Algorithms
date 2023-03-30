class Solution {
private:
    int solve(vector<int>& obs, int n, int currLane, int currPos){
        // Base case
        if(currPos == n) return 0;

        // check next position in same lane
        if(obs[currPos + 1] != currLane) return solve(obs, n, currLane, currPos+1);

        // Side ways jump
        else{
            int minJumps =INT_MAX;
            for(int i = 1; i <= 3; i++){
                // Jump in lane only if it is not curr lane
                if(currLane != i){
                    // Jump in lane only it does not has obstacle
                    if(obs[currPos] != i){
                        minJumps = min(minJumps, 1+ solve(obs, n, i, currPos));
                    }
                }
            }
            return minJumps;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        return solve(obstacles,n,  2, 0);
    }
};
