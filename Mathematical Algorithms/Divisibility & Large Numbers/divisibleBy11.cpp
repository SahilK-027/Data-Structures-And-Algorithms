#include <bits/stdc++.h>
using namespace std ;

class Solution{
private:
    long long getSum(string &s, int startIdx){
        long long sum = 0;
        for(int i = startIdx; i < s.length(); i+=2){
            sum += int(s[i] - '0');
        }
        return sum;
    }
public:	
	int divisibleBy11(string s)
	{
	    long long evenSum = getSum(s, 0);
	    long long oddSum = getSum(s, 1);
	    return abs(evenSum - oddSum) % 11 == 0;
	}
};
int main()
{
    Solution* q1 = new Solution();
    cout<<q1->divisibleBy11("1331")<<endl;
    return 0;
}