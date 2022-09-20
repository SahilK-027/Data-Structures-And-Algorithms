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

//Approach 2: Using Recursion
/*
TC: O(N)
SC: O(N)
*/

void reverse_2(queue<int>& q){
    // Base Case
    if(q.empty()){
        return;
    }

    // Store and remove front element aside
    int element = q.front();
    q.pop();

    // Call recursion to reverse remaining queue
    reverse_2(q);

    //cout<<element<<" ";

    // Before returning push the removed element back in queue
    q.push(element);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reverse(q);
    reverse_2(q);
    return 0;
}



