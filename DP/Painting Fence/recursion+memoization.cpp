#include <bits/stdc++.h>
#define M 1000000007
int add(int a,int b){
    return ((a%M)+(b%M))%M;
} 

int mult(int num1, int num2){
    return ((num1%M) * 1LL * (num2%M))%M;
}
int solveMemoization(int n,int k,vector<int>&dp){
    //base case
    if(n==1)
        return k;
    if(n==2)
        return add(k,mult(k,k-1));
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=add(mult(solveMemoization(n-2,k,dp),k-1),mult(solveMemoization(n-1,k,dp),k-1));

}
int numberOfWays(int n, int k) {
    vector<int>dp(n+1,-1);
    return solveMemoization(n,k,dp);
}
