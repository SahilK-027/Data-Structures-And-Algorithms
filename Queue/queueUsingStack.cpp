/*
Approach:
Push operation -> Push operation will get performed on input stack.
Pop operation -> Pop operation will get performed on output stack.

push(){
    this->input.push(x);
}
pop(){
    if(output stack is empty){
        then add all elements from input stack to output stack
        and then pop element from output stack
    }
    else{
        directly pop from output stack
    }
}
empty(){
    if both input and output stacks are empty then we can say our queue is empty
}
*/
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    
    void push(int x) {
        this->input.push(x);
    }
    
    int pop() {
        if(this->output.empty())
        {
            while(!this->input.empty()){
                int element = this->input.top();
                this->output.push(element);
                this->input.pop();
            }
        }
        int ans = this->output.top();
        this->output.pop();
        return ans;
    }
    
    int peek() {
        if(this->output.empty())
        {
            while(!this->input.empty()){
                int element = this->input.top();
                this->output.push(element);
                this->input.pop();
            }
        }
        int ans = this->output.top();
        return ans;
    }
    
    bool empty() {
        if(this->input.empty() && this->output.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
