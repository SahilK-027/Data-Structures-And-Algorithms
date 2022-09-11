/*
Delete middle element from stack
Problem Statement : You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so
that the size of resulting stack is 'N'.
*/

void solve(stack<int>&inputStack, int size ,int count = 0){
    // Base Case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    // Otherwise
    // Store and remove the top element
    int topElement = inputStack.top();
    inputStack.pop();
    solve(inputStack,size,count+1);
    
    //And before returning push the top element again in stack
    inputStack.push(topElement);
}
void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack,N);
}
