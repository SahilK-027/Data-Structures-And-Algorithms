/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i]=='('){
                // For open brace push it on stack
                st.push(s[i]);
            } 
            else
            {
                // Else close brace has found
                if(!st.empty())
                {
                    // If stack is not empty means this close brace has an open brace previously
                    st.pop();
                }
                else{
                    // this close brace does not have an open brace previously
                    cnt++;
                }
            }
        }
        if(st.empty()){
            //string is balaced 
            return cnt;
        }
        else{
            return cnt + st.size();
        }
    }
};
