/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<stack>
int findCelebrity(int n) {
    // Storing all the person in stack
 	stack<int> st;
    for(int i = 0 ; i < n ; i++){
        st.push(i);
    }
    // Discarding all noncelebrity
    while(st.size() != 1 && !st.empty()){
        int person1 = st.top();
        st.pop();
        int person2 = st.top();
        st.pop();
        if(knows(person1,person2)){
            // Person1 knows person2 ,so p1 cant be celebrity
            if(knows(person2,person1)){
                //And person2 also knows person 1 ,so p2 cant be celebrity
                continue;
            }
            else{
                //Person2 not knows person1, so 2 can be celebrity
                st.push(person2);
            }
        }
        else if(knows(person2,person1)){
            //person2 knows person1
            // also we are in this block because Person1 not knows person2
            // So person 1 can be celebrity
            st.push(person1);
        }
    }
    
    // After ending above while loop if stack is empty means no one is celebrity
    if(st.empty()){
        return -1;
    }
    // If stack is not empty means there is one potential person who can be celebrity
    // And for a person to be celebrity we need to check two cnditions
    // 1. He knows no one and 
    // 2. No one knows him
    else{
        bool known = false;
        for(int i = 0;i<n;i++) // Checking celebrity with all persons
        {
            // if celebrity knows ith person return -1
           if(knows(st.top(),i)){
               return -1;
            }
            // else if ith person knows celebrity mark known as true
            else if(knows(i,st.top())){
                known = true;
            }
        }
        if(known)
        {
            // if celebrity is known return celebrity
            return st.top();
        }
        else
        {
            // else he is not celebrity
            return -1;
        }
    }
}
