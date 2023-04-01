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
