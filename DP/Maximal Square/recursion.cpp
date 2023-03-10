class Solution {
private:
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi){
        // Base case
        if(i >= row || j >= col) return 0;

        // Explore for all directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int bottom = solve(matrix, i+1, j, row, col, maxi);
        int diagonal = solve(matrix, i+1, j+1, row, col, maxi);

        // If current elment is 1 then process otherwise you cannot form sqare so return 0
        if(matrix[i][j] == '1'){
            // 1 + because we will incluyde current block
            int ans = 1 + min(right, min(bottom, diagonal));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        solve(matrix, i, j,row, col,maxi);
        return maxi * maxi;
    }
};
