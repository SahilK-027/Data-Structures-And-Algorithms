class Solution {
private:
    void solve(vector<int>& nums, int prev, int curr , int &size, vector<int>& subseq){
        if(curr >= nums.size()){
            int curr_ans = subseq.size();
            size = max(size, curr_ans);
            return;
        }
        // Include 
        if(prev == -1 || nums[curr] > nums[prev]){
            subseq.push_back(nums[curr]);
            solve(nums, curr, curr+1, size, subseq);
            subseq.pop_back();
        }
        // Exclude
        solve(nums, prev, curr+1, size, subseq);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int curr = 0;
        int prev = -1;
        vector<int> subseq;
        int size = INT_MIN;
        solve(nums, prev, curr, size, subseq);
        return size;
    }
};


/* ================================================================================================
                        WITHOUT BUILDING ACTUAL SUBSEQUENCE
==================================================================================================== */

class Solution {
private:
    int solve(vector<int>& nums, int prev, int curr){
        if(curr >= nums.size()){
            return 0;
        }
        // Include 
        int include = INT_MIN;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums, curr, curr+1);
        }
        // Exclude
        int exclude = solve(nums, prev, curr+1);

        return max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int curr = 0;
        int prev = -1;
        return solve(nums, prev, curr);
    }
};
