/*
You're given a stack consisting of 'N' integers. Your task is to sort this stack in descending
order using recursion.
*/

void insert_in_sorted_way(stack<int> &stack , int element){
    //Base case
    if(stack.empty() || stack.top() <=  element){  //This condition will determine if the stack will get sorted in ascending or descending order
        stack.push(element);
        return;
    }
    
    // Remove and store top
    int top_element = stack.top();
    stack.pop();
    
    // Go inside the stack
    insert_in_sorted_way(stack ,element);
    
    // While returning push top_element back in stack
    stack.push(top_element);
}
void sortStack(stack<int> &stack){
	// Base case
    if(stack.empty()){
        return;
    }
    // Remove and store top
    int top_element  = stack.top();
    stack.pop();
    
    // Go inside stack
    sortStack(stack);
    
    // While returning push the top_element in sorted way
    insert_in_sorted_way(stack,top_element);
}
