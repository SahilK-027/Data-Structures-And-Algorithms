/*
Given valid mathematical expressions in the form of a string. You are supposed to
return true if the given expression contains a pair of redundant brackets, else
return false. The given string only contains '(, ')', 't',', **', /' and lowercase
English letters.
Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by
needless/ useless brackets.
*/



#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0 ; i< s.length(); i++){
        char ch = s[i];
        if(ch == '('||ch == '+'||ch == '-'|| ch == '/'|| ch == '*'){
            st.push(ch);
        }
        else{
            // Either a to z or )
            if(ch == ')')
            {
                char top = st.top();
                if(top == '+'||top == '-'|| top == '/'|| top == '*')
                {
                    if(!st.empty() )
                    while(st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    return true;
                }
            }
            else{
                continue;
            }
        }
    }
    return false;
}
