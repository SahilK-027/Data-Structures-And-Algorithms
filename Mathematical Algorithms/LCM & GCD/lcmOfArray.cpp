#include <bits/stdc++.h>
using namespace std ;

class Solution
{
#define M 1000000007
private:
    long long getGCD(long long a, long long b)
    {
        if (a == 0)
            return b;
        return getGCD(b % a, a);
    }
    long long getLCM(long long a, long long b)
    {
        return (a * b) / getGCD(a, b);
    }

public:
    int lcmOfArray(int N, int arr[])
    {
        if (N == 1)
            return arr[0];
        long long lcm = 0;
        lcm = getLCM(arr[0] * 1ll, arr[1] * 1ll) % M;
        for (int i = 2; i < N; i++)
        {
            lcm = getLCM(lcm, arr[i] * 1ll) % M;
        }
        return lcm;
    }
};

int main()
{
    Solution ob;
    int arr[5] = {1,2,3,4,5};
    cout<<ob.lcmOfArray(5, arr)<<endl;
    return 0;
}