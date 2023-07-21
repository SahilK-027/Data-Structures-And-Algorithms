#include <bits/stdc++.h>
using namespace std ;
void __init__LPS(vector<int>& LPS, string& s){
    // Length of current LPS is 0
    int len = 0;
    // LPS for 0th char is always 0
    LPS[0] = 0;
    int i = 1;
    while(i < LPS.size()){
        if(s[i] == s[len]){
            // We can get suffix = prefix
            len++;
            LPS[i] = len;
            i++;
        }
        else{
            if(len == 0){
                LPS[i] = 0;
                i++;
            }
            else{
                len = LPS[len - 1];
            }
        }
    }
}
int main()
{
    string s = "aaaabbbaaaa";
    vector<int>LPS(s.length(), 0);
    __init__LPS(LPS, s);
    for(int i = 0 ; i < LPS.size();i++){
        cout<<LPS[i]<<' ';
    }
    cout<<endl;
    return 0;
}