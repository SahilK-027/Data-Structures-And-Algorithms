// MEMO
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

unordered_map<int, int> memo;

int solve(int n, int k, vector<int> &height)
{
    if (n == 0)
    {
        return 0;
    }

    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }

    int op = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int curr_ans = INT_MAX;
        if (n - i >= 0)
        {
            curr_ans = abs(height[n] - height[n - i]) + solve(n - i, k, height);
        }
        op = min(op, curr_ans);
    }

    memo[n] = op;
    return op;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    memo.clear();
    return solve(n - 1, k, height);
}
