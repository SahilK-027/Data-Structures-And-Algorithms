// This is logic

// How to remove the contribution of one number from contiguous ORs.
// EX: a | b | c | d = e
// then if I want to remove the contribution of `a` for this to get
// a new answer of b | c | d = k How can I do that?

// The problem is in OR operation,
// 1 | 1 = 1
// 1 | 0 = 1
// 0 | 1 = 1
// 0 | 0 = 0

// So lets say our a = 1, b = 2, c = 3 and d = 4
// a | b | c | d = 7
// But on each step it will look like this

//   a    b     c     d
// 0001  0011  0011  0111
// i                  j
//        i           j

// So if we have to remove 0001 from 0111 now how can we do that?

// The method is instead of ORing at each step just take sum of each bit
// As
// 1 | 1 = 1
// 1 | 0 = 1
// 0 | 1 = 1
// 0 | 0 = 0

// We get contribution of 1 in three cases
// So while removing this contrbution we are not sure if originally the
// contribution was came by  1 | 1 or 1 | 0 or 0 | 1

// The way to do it is
//   a    b     c     d
// 0001  0011  0022  0122

// How i did this?
// a = 1 0001
// b = 2 0010
// so save a | b = 0001 + 0010 = 0011
// c = 3 0011
// so save a | b | c = 0001 + 0010 + 0011 = 0022
// d = 4 0100
// so save a | b | c | d = 0001 + 0010 + 0011 + 0100 = 0122

// Now when we have to remove the contribution of a from a | b | c | d
// we can do it by subtracting a from the result
// 0122 - 0001 = 0111

// Here amy number positive other that 0 is considered as 1
// like 0122 = 0111 (But we have considered 0111 as 0122 for removing contribution of a afterwards)

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
private:
    void add(vector<int> &bitvector, int num)
    {
        int i = 0;
        while (num > 0)
        {
            bitvector[i] = bitvector[i] + (num % 2);
            num /= 2;
            i++;
        }
    }
    void subtract(vector<int> &bitvector, int num)
    {
        int i = 0;
        while (num > 0)
        {
            bitvector[i] = bitvector[i] + (-1 * (num % 2));
            num /= 2;
            i++;
        }
    }
    bool isContributionMoreThanEqualToK(vector<int> &bitvector, int k)
    {
        int bitVectorVal = 0;
        for (int i = 0; i < 32; i++)
        {
            bitVectorVal += (bitvector[i] ? 1 : 0) * pow(2, i);
        }
        return bitVectorVal >= k;
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        vector<int> bitvector(32, 0);
        while (j < n)
        {
            // Add the contribution of curr nums[j] to bit value
            add(bitvector, nums[j]);

            while (isContributionMoreThanEqualToK(bitvector, k) && i <= j)
            {
                ans = min(ans, j - i + 1);
                // remove the contribution of nums[i] from bit value
                subtract(bitvector, nums[i]);
                i++;
            }

            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums; 
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    int k = 5; 

    int result = solution.minimumSubarrayLength(nums, k);
    if (result != -1){
        cout << "The minimum subarray length with contribution >= " << k << " is: " << result << endl;
    }
    else{
        cout << "No subarray found with contribution >= " << k << endl;
    }

    return 0;
}
