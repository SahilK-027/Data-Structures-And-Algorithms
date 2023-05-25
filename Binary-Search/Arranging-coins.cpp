/**
 * @file Arranging-coins.cpp
 * @brief
 * You have n coins and you want to build a staircase with these coins.
 * The staircase consists of k rows where the ith row has exactly i coins.
 * The last row of the staircase may be incomplete.
 * Given the integer n, return the number of complete rows of the staircase you will build.
 */

/**
 * @brief I/O EXPLANATION
 * Input: n = 5
 * Output: 2
 * Explanation: Because the 3rd row is incomplete, we return 2.
 */

// Using BS
int arrangeCoins(int n)
{
    int s = 1;
    int e = n;
    double m = s + (e - s) / 2;
    while (s <= e)
    {
        long long coins_used = m / 2 * (m + 1);
        if (coins_used == n)
        {
            return (int)m;
        }
        else if (n < coins_used)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }
    return e;
}