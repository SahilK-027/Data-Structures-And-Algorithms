class Solution {
private:
    int solve(vector<int>& slices, int s, int e, int n){
        // Base case if slices_we_can_eat == 0 or s > e
        if(n == 0 || s > e)
            return 0;
        int include = slices[s] + solve(slices, s +2,e, n-1);
        int exclude = solve(slices, s+1, e , n);
        return max(include, exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        // Finding out the total number of slices
        int total_slices = size ;
        // As there are 3 friends each will get total/3 slices
        int slices_we_can_eat = total_slices / 3;
        
        int option1 = solve(slices, 0, size-2, slices_we_can_eat);
        int option2 = solve(slices, 1, size-1, slices_we_can_eat);

        return max(option1, option2);
    }
};
