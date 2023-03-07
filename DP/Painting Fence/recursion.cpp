#include <bits/stdc++.h> 
#define M 1000000007
int solve(int n, int k) {
    // Base case
    // We have only one pole
    if(n == 1) return k;
    if(n == 2) return (k * k) % M;

    // Recursion
    int last_same = (solve(n-2, k) * (k-1)) % M;
    int last_diff = (solve(n-1, k) * (k-1)) % M;

    return ( last_same + last_diff ) % M;

}

int numberOfWays(int n, int k) {
    return solve(n, k) % M;
}
