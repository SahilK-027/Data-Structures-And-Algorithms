class Solution {
private:
    int SO(vector<int>& nums){
        int n = nums.size();
        vector<int> current(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr = n-1 ; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // Include 
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + next[curr+1];
                }
                // Exclude
                int exclude = 0 + next[prev+1];

                //  Prev can be -1 as well so make prev + 1 
                current[prev+1] =  max(include, exclude);
            }
            next = current;
        }
        return next[0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        return SO(nums);
    }
};
