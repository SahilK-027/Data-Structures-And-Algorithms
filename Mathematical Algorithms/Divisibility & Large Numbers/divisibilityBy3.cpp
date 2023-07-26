#include <bits/stdc++.h>
using namespace std;
bool check(string str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += int(str[i] - '0');
    }
    if (sum % 3 == 0)
        return true;
    return false;
}
int main()
{
    string str = "122";
    check(str) ? cout << "Yes" << endl : cout << "No " << endl;
    return 0;
}