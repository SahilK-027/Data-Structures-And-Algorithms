class Solution {
private:
    int solve(vector<int>& arr, int i, int time){
        if( i >= arr.size()) return 0;

        // Include case
        int include = time * arr[i] + solve(arr, i+1, time+1);
        // Exclude case
        int exclude = 0 + solve(arr, i+1, time);

        return max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int time = 1;
        return solve(arr, 0, time);
    }
};
