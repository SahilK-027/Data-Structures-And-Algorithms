#include <bits/stdc++.h>
using namespace std;
// TOP - DOWN DP
// Steps in MEMOIZATION
// STEP 1: Create DP array just before function call + pass in fuction call
// STEP 2: Store answer in DP array
// STEP 3: Just after base case check if answer is already there in DP array if yes return ans
int fib_memo(int n, vector<int> &dp)
{
    if (n < 2)
        return n;
    // Step 3:
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    // Step 2
    dp[n] = ans;
    return ans;
}
int main()
{
    int n = 7;
    // Step 1
    vector<int> dp(n + 1, -1);

    // Fib with memoization
    cout << fib_memo(n, dp) << endl;
    return 0;
}
