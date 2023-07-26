#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:	
	int divisibleBy4(string str)
	{
	    if(str.length() == 1) return stoi(str) % 4 == 0;
	    int n = str.length();
	    int last = int(str[n-1] - '0');
	    int secondlast = int(str[n-2] - '0');
	    int digits = secondlast * 10 + last;
	    return digits % 4 == 0;
	    
	}
};
int main()
{
    Solution* q1 = new Solution();
    cout<<q1->divisibleBy4("12")<<endl;
    return 0;
}