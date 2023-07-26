#include <bits/stdc++.h>
#include<cassert>
using namespace std ;

class Solution{
private:
    int solve(int a, int b, int &x, int &y){
        if(a == 0){
            x = 0;
            y = 1;
            return b;
        }
        int x1 = 0, y1 = 0;
        int gcd = solve(b % a, a, x1, y1);
        
        x = y1 - (b / a)*x1;
        y = x1;
        
        return gcd;
    }
public:
    vector<int> gcd(int a, int b){
        int x = 0;
        int y = 0;
        int gcd = solve(a, b, x, y);
        return {gcd, x, y};
    }
};

bool compareVectors(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

int main()
{
    Solution ob;
    vector<int> result = ob.gcd(35, 15);
    assert(compareVectors(result, {5, 1, -2}));
    return 0;
}