#include <bits/stdc++.h>
using namespace std ;

class Solution{
private:
    bool solve(int num){
        if(num < 0) return solve(-1 * num);
        if(num == 0|| num == 7) return true;
        if(num < 10) return false;

        int last_digit = num % 10;
        int rem_digit = (num - last_digit)/10;
        int new_digit = rem_digit - (2 * last_digit);

        return solve(new_digit);
    }
public:	
	int divisibleBy7(int num)
	{
        return solve(num);
	}
};

class Solution2
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
        return abs(sum) % 7 == 0;
    }

public:
    int divisibleBy7(string num)
    {
        return solve(num);
    }
};
int main()
{
    Solution* q1 = new Solution();
    Solution2* q2 = new Solution2();
    cout<<q1->divisibleBy7(371)<<endl;
    cout<<q2->divisibleBy7("5274997") << endl;
    return 0;
}