#include <bits/stdc++.h> 
/*
Approach: n = q.size()
Step 1: Reverse first k
step 2: POP n-k and push in queue
*/
queue<int> reverseElements(queue<int> q, int k)
{
    int n = q.size();
    stack<int> st;
    int cnt =0;
    while(cnt<k){
        int element = q.front();
        st.push(element);
        q.pop();
        cnt++;
    }
    while(!st.empty()){
        int element = st.top();
        q.push(element);
        st.pop();
    }
    
    cnt = 0;
    while(cnt<n-k){
        int element = q.front();
        q.pop();
        q.push(element);
        cnt++;
    }
    return q;
}
