#define M 1000000007
long long int countDerangements(int n) {
    // Base case
    if( n < 2 ) return 0;
    if( n == 2) return 1;
    // Recursive call
    return  ((n-1) % M * (countDerangements(n-1) + countDerangements(n-2)))%M;
}
