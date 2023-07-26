#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(string num)
    {
        int n = num.length();
        if (n % 3 == 1)
        {
            reverse(num.begin(), num.end());
            num += "00";
            reverse(num.begin(), num.end());
        }
        else if (n % 3 == 2)
        {
            reverse(num.begin(), num.end());
            num += "0";
            reverse(num.begin(), num.end());
        }
        long long sum = 0;
        for (int i = 0; i < num.length(); i += 3)
        {
            if (i % 2 == 0)
            {
                // Add
                string curr_num = num.substr(i, 3);
                sum += stoi(curr_num);
                
            }
            else
            {
                // Subtract
                string curr_num = num.substr(i, 3);
                sum -= stoi(curr_num);
            }
        }
        return abs(sum) % 13 == 0;
    }

public:
    int divisibleBy13(string num)
    {
        return solve(num);
    }
};
int main()
{
    Solution *q1 = new Solution();
    cout << q1->divisibleBy13("83959092724653") << endl;
    return 0;
}