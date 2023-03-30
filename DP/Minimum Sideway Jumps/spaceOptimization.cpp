class Solution {
private:
    int SO(vector<int>& obs){
        int n = obs.size()-1;

        vector<int>curr(4, 1000000);
        vector<int>next(4, 1000000);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int currLane =1; currLane <= 3; currLane++){
                // check next position in same lane
                if(obs[currPos + 1] != currLane){
                    curr[currLane] = next[currLane];
                } 

                // Side ways jump
                else{
                    int minJumps = 1000000;
                    for(int i = 1; i <= 3; i++){
                        // Jump in lane only if it is not curr lane
                        if(currLane != i){
                            // Jump in lane only it does not has obstacle
                            if(obs[currPos] != i){
                                minJumps = min(minJumps, 1 + next[i]);
                            }
                        }
                    }
                    curr[currLane] = minJumps;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1] , 1 + next[3]));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return SO(obstacles);
    }
};
