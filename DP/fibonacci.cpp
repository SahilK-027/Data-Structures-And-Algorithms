#include <bits/stdc++.h>
using namespace std;

// Recusrive
int fibo(int n){
    if(n < 2) return n;
    return fibo(n-1) + fibo(n-2);
}



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
        cout<<"Applied dp for "<<n<<endl;
        return dp[n];
    }
    int ans = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    // Step 2
    dp[n] = ans;
    return ans;
}



// BOTTOM - UP DP
// Steps in TABULARIZATION
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




// SPACE OPTIMIZATION
int fib_SO(int n)
{
    if(n < 2){
        return n;
    }
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for(int i = 2 ; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return  curr;
}
int main()
{
    int n = 7;
    // Step 1
    vector<int> dp(n + 1, -1);
    // Recursive 
    //  cout << fib(n, dp) << endl;

    // Fib with memoization
    cout << fib_memo(n, dp) << endl;

    // Bottom up - tabularization
    cout << fib_tab(n) << endl;

    // Space optim
    cout << fib_SO(n) << endl;
    return 0;
}
