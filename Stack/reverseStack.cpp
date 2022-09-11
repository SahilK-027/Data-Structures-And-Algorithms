void pushAtBottom(stack<int> &stack,int x){
    //If stack is empty push the element in stack
    if(stack.empty()){
        stack.push(x);
        return;
    }
    // Remove and store the top elemement from stack
    int topElement = stack.top();
    stack.pop();
    // Call insert at bottom and go till the end of stack
    pushAtBottom(stack,x);
    
    // While coming back push the removed top element back in stack
    stack.push(topElement);
}
void reverseStack(stack<int> &stack) {
    //Base Case
    if(stack.empty()){
        return;
    }
    // Remove and store the top elemement from stack
    int top = stack.top();
    stack.pop();
    
    //Ask recursion to reverse the stack
    reverseStack(stack);
    
    // Once recursion has reversed the stack push top element at the bottom of stack 
    pushAtBottom(stack,top);
}
