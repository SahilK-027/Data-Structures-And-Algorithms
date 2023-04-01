class Solution {
private:
    int so(vector<int>& arr){
        int n = arr.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        for(int i = n - 1 ; i >= 0; i--){
            for(int time = i  ; time >= 0; time--){
                // Include case
                int include = (time + 1)* arr[i] + next[time+1];
                // Exclude case
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return so(arr);
    }
};
