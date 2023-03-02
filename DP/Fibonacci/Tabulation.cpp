#include <bits/stdc++.h>
using namespace std;
// BOTTOM - UP DP
// Steps in Tabulation
// STEP 1: Create DP array in fuction itself
// STEP 2: Analyze base cases of recursive function and then modify DP array accordingly
// STEP 3: for loop + rec logic
int fib_tab(int n)
{
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n = 7;
    // Bottom up - tabularization
    cout << fib_tab(n) << endl;
    return 0;
}
