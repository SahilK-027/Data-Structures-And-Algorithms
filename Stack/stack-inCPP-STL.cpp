#include <bits/stdc++.h>
using namespace std ;
int main()
{
    //Creation of stack
    stack<int> s;

    // Push operation
    s.push(10);
    s.push(20);

    // Pop operation
    s.pop();

    //Peek element
    cout<<"Top element of stack is: "<<s.top()<<"\n";
    
    //Checking if stack is empty or not
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    // Size
    cout<<"size of stack is: "<<s.size()<<endl;
    return 0;
}