//Approach 1: Using Stack
/*
TC: O(N)
SC: O(N)
*/
#include <bits/stdc++.h>
using namespace std ;
void reverse(queue<int>& q){
    stack<int> st;
    while(!q.empty()){
        int element = q.front();
        st.push(element);
        q.pop();
    }
    while(!st.empty()){
        int element = st.top();
        cout<<element<<" ";
        q.push(element);
        st.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reverse(q);
    return 0;
}
