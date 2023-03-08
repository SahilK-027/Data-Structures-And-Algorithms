class Solution {
private:
    int solve(int i, int n, vector<int>& days, vector<int>& costs){
        // Base case
        if(i >= n) return 0;

        // Option 1: Buy 1 day pass
        int option1 = costs[0] + solve(i+1, n, days, costs);
        // Option 2: Buy 7 day pass
        // Go seven day ahead
        int x;
        for(x = i; x < n && days[x] < days[i] + 7; x++);
        int option2 = costs[1] + solve(x, n, days, costs);
        // Option 3: Buy 30 day pass
        for(x = i; x < n && days[x] < days[i] + 30; x++);
        int option3 = costs[2] + solve(x, n, days, costs);

        return min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int i = 0;
        return solve(i, n, days, costs);
    }
};
