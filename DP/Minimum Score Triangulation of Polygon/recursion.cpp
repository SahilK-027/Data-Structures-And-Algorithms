class Solution {
private:
    int solve(vector<int>& values, int i, int j){
        // Base case
        if(i + 1 == j) return 0;

        // Select k
        int ans = INT_MAX;
        for(int k = i + 1; k <= j -1 ; k++){
            int curr_ans = values[i] * values[j] *  values[k] + 
            solve(values, i, k) + 
            solve(values, k, j);

            ans = min(ans, curr_ans);
        }

        // Return ans
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        return solve(values, 0, values.size()-1);
    }
};
