/*
Approach : Recursive solution

Base case :
1. Initially count will be 0
2. If count == stack.size() push(element) in answer stack ans return

Step 1: Remove the top element of stack and store it somewhere

Recursive call :
With recursion go till the bottom of stack
And as soon as bottom is reached with the base case push(element) to the bottom of stack.

Processing :
While returning back from recursion store the removed top element in answer stack again.
*/

stack<int> solve(stack<int>& ans,stack<int>& myStack,int size, int x,int count = 0){
    //Base case
    if(count == size){
        ans.push(x);
        return ans;
    }
    //Otherwise
    //Step 1
    int topElement = myStack.top();
    myStack.pop();
    //Recursive call
    solve(ans,myStack,size,x,count+1);
    
    // While Returning back store the top element in ans
    ans.push(topElement);
    //Return the answer
    return ans;
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int> ans;
    return solve(ans,myStack,myStack.size(),x);
}
